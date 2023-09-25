#include <fstream>

using namespace std;

ifstream cin("aimi.in");
ofstream cout("aimi.out");

const int NMAX = 100005;
const int INF = 2e9;
int n, m, t, a, b, x, arr[NMAX], segment_tree[4 * NMAX];

void Build(int node, int left, int right) {
    if (left == right) {
        segment_tree[node] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    Build(2 * node, left, mid);
    Build(2 * node + 1, mid + 1, right);
    segment_tree[node] = min(segment_tree[2 * node],
                             segment_tree[2 * node + 1]);
}

void Update(int node, int left, int right, int qleft, int qright, int delta) {
    if (left > right)                   return;
    if (qleft <= left && right <= qright) {
        segment_tree[node] = delta;
        cout << delta << ' ' << left << ' ' << right  << '\n';
        return;
    }
    if (qleft > right || qright < left) return;
    int mid = left + (right - left) / 2;
    Update(2 * node, left, mid, qleft, qright, delta);
    Update(2 * node + 1, mid + 1, right, qleft, qright, delta);
    segment_tree[node] = min(segment_tree[2 * node],
                             segment_tree[2 * node + 1]);
}

int Query(int node, int left, int right, int qleft, int qright) {
    if (left > right)                       return INF;
    if (qleft <= left && right <= qright)   return segment_tree[node];
    if (qleft > right || qright < left)     return INF;
    int mid = left + (right - left) / 2;
    return min(Query(2 * node, left, mid, qleft, qright),
               Query(2 * node + 1, mid + 1, right, qleft, qright));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    Build(1, 1, n);
    cin >> m;
    while (m--) {
        cin >> t >> a >> b;
        if (t == 1) cout << Query(1, 1, n, a, b) << '\n';
        else {
            cin >> x;
            Update(1, 1, n, a, b, x);
        }
    }
    cin.close();
    cout.close();
    return 0;
}