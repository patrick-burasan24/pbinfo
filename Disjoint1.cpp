#include <iostream>
#include <cstdio>
#include <vector>

int maxi = 1;

class DisjointSetUnion {
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int n;
    
    public:
        DisjointSetUnion(const int _n) {
            this->n = _n;
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 1; i <= n; i++)
                parent[i] = i;
        }
        ~DisjointSetUnion() { }

        int find(int u) {
            if (u == parent[u])
                return u;
            return parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v)
                return;
            
            if (size[v] > size[v])
                std::swap(u, v);
            
            parent[v] = u;
            size[u] += size[v];

            maxi = std::max(maxi, size[u]);
        }
};

int n, m;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    DisjointSetUnion dsu(n);

    while(m--) {
        int cod, x, y;
        std::cin >> cod;
        if (cod == 1) {
            std::cin >> x >> y;
            dsu.unite(x, y);
        }
        else if (cod == 2) {
            std::cin >> x >> y;
            if (dsu.find(x) == dsu.find(y))
                std::cout << "DA\n";
            else
                std::cout << "NU\n";
        }
        else
            std::cout << maxi << '\n';
    }
    return 0;
}