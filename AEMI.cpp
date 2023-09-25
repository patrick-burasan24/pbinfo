#include <fstream>

using namespace std;

ifstream cin("aemi.in");
ofstream cout("aemi.out");

const int NMAX = 100005;
const int INF = 2e9;
int n, m, t, a, b, arr[NMAX], segment_tree[4 * NMAX];

void Build(int node, int left, int right) {
    if (left == right) {
        segment_tree[node] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    Build(2 * node, left, mid);
    Build(2 * node + 1, mid + 1, right);
    segment_tree[node] = min(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

void Update(int node, int left, int right, int position, int new_value) {
    if (left == right) {
        segment_tree[node] = new_value;
        return;
    }
    int mid = left + (right - left) / 2;
    if (position <= mid) Update(2 * node, left, mid, position, new_value);
    else Update(2 * node + 1, mid + 1, right, position, new_value);
    segment_tree[node] = min(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

int Query(int node, int qleft, int qright, int left, int right) {
    if (qleft <= left && right <= qright) return segment_tree[node];
    if (qleft > right || qright < left)   return INF;
    int mid = left + (right - left) / 2;
    return min(Query(2 * node, qleft, qright, left, mid),
        Query(2 * node + 1, qleft, qright, mid + 1, right));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    Build(1, 1, n);
    cin >> m;
    while (m--) {
        cin >> t >> a >> b;
        if (t == 1) cout << Query(1, a, b, 1, n) << '\n';
        else Update(1, 1, n, a, b);
    }
    cin.close();
    cout.close();
    return 0;
}