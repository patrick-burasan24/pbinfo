#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

class SegmentTree {
    private:
        vector<ll> tree;
        int n;
    public:
        SegmentTree(int _n) {
            this->n = _n;
            tree.assign(n << 2, 0);
        }

        void Update(int node, int l, int r, int pos) {
            if (l == r) {
                tree[node]++;
                return;
            }
            if (pos > r || pos < l)
                return;
            
            int mid = (l + r) >> 1;

            if (pos <= mid)
                Update(node << 1, l, mid, pos);
            else
                Update(node << 1 | 1, mid + 1, r, pos);
            
            tree[node] = tree[node << 1] + tree[node << 1 | 1];
        }

        ll Query(int node, int l, int r, const int x, const int y) {
            if (x <= l && r <= y) 
                return tree[node];
            if (x > r || y < l)
                return 0;
            
            int mid = (l + r) >> 1;
        
            return Query(node << 1, l, mid, x, y) +
                   Query(node << 1 | 1, mid + 1, r, x, y);
        }
};

ll Count(vector<int> &arr, int n) {
    ll counter = 0;
    SegmentTree segTree(n);
    for (int i = 1; i <= n; i++) {
        counter += segTree.Query(1, 1, n, arr[i], n);
        segTree.Update(1, 1, n, arr[i]);
    }
    return counter;
}

int n;
vector<int> arr;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << Count(arr, n) << '\n';
    return 0;
}