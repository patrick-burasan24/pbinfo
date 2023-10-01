#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

std::ifstream cin("harta3.in");
std::ofstream cout("harta3.out");

/**
 * Structs to store information about the input data
 */

struct Punct {
    int ID;
    int x;
    int y;
};

struct Edge {
    Punct A;
    Punct B;
    float cost;

    friend bool operator < (const Edge &X, const Edge &Y) {
        return X.cost < Y.cost;
    }
};

/**
 * Class that creates disjoint sets of connected vertices 
*/

class DisjointSetUnion {
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int n;
    
    public:
        DisjointSetUnion(int _n) {
            this->n = _n;
            parent.resize(n + 1);
            size.resize(n + 1, 1);

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

/**
 * Class to make from scratch the MST
 */

class MinimumSpanningTree {
    private:
        int n;
    
    public:
        MinimumSpanningTree(int _n) {
            this->n = _n;
        }
        ~MinimumSpanningTree() { }

        float kruskal(std::vector<Edge> &list) {
            std::sort(list.begin(), list.end());
            DisjointSetUnion dsu(n);

            float res = 0;

            for (auto w : list) {
                int u = w.A.ID;
                int v = w.B.ID;
                float c = w.cost;

                if (dsu.find(u) != dsu.find(v)) {
                    dsu.unite(u, v);
                    res += c;
                }
            }

            return res;
        }
};

int n, x, y;
std::vector<Punct> v;
std::vector<Edge> list;

int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].ID = i;
    }

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            float dist = sqrt(1.0 * (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y));
            list.push_back({v[i], v[j], dist});
        }
    
    MinimumSpanningTree mst(n);
    cout << std::fixed << std::setprecision(4);
    cout << mst.kruskal(list) << '\n';
    return 0;
}