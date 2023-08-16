#include <fstream>
#include <map>
#include <set>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

class Graph {
    public:
        map<int, bool> visited;
        // Se va folosi un set in loc de o lista pentru a garanta ordinea lexicografica
        // ceruta in enunt.
        map<int, set<int> > adj;                      
    
    inline void addEdge(int const &u, int const &v);

    inline void dfs(int const &node);

};

inline void Graph::addEdge(int const &u, int const &v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

inline void Graph::dfs(int const &node) {
    fout << node << ' ';
    visited[node] = true;
    for (auto u : adj[node])
        if (!visited[u])
            dfs(u);
}

int n, m, x, y, edge;
Graph g;

int main() {
    fin >> n >> m >> edge;
    while (m--) {
        fin >> x >> y;
        g.addEdge(x, y);
    }
    g.dfs(edge);
    fin.close();
    fout.close();
    return 0;
}