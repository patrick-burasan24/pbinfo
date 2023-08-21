#include <fstream>
#include <vector>

using namespace std;

ifstream fin("euler.in");
ofstream fout("euler.out");

int const NMAX = 1e5+1;
int n, u, v, k, edge, from[NMAX], to[NMAX];
vector < int > ans, adj[NMAX];
bool used[NMAX];

void euler(int node) {
    for (auto it : adj[node]) {
        edge = it;
        if (!used[edge]) {
            used[edge] = true;
            euler((node ^ from[edge] ^ to[edge])); 
        }
    }
    ans.push_back(node);
}

int main() {
    fin >> n;
    while (fin >> u >> v) {
        k++;
        adj[u].push_back(k);
        adj[v].push_back(k);
        from[k] = u;
        to[k] = v;
    }
    euler(1);
    fout << ans.size() << '\n';
    for (auto it : ans)
        fout << it << ' ';
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}