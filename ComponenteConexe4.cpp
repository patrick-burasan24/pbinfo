#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

class DisjointSetUnion {
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int n;
    
    public:
        DisjointSetUnion(const int _n) {
            this->n = _n;
            parent.resize(n + 1);
            size.resize(n + 1, 0);

            for (int i = 1; i <= n; i++)
                parent[i] = i;
        }
        ~DisjointSetUnion() { }

        int find(const int &u) {
            if (u == parent[u])
                return u;
            return parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v)
                return;
            
            if (size[v] > size[u])
                std::swap(u, v);
            
            parent[v] = u;
            size[u] += size[v];
        }
};

int n, m;
std::pair<int, int> edges[500005];
std::vector<int> ans(500005);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    for (int i = 0; i < m; i++) 
        std::cin >> edges[i].first >> edges[i].second;
    
    DisjointSetUnion dsu(n);

    ans[m - 1] = n;

    for (int i = m - 1; i >= 0; i--) {
        int p = edges[i].first;
        int q = edges[i].second;
        if (dsu.find(p) != dsu.find(q)) {
            dsu.unite(p, q);
            ans[i - 1] = ans[i] - 1;
        }
        else
            ans[i - 1] = ans[i];
    }

    for (int i = 0; i < m; i++)
        std::cout << ans[i] << '\n';
    return 0;
}