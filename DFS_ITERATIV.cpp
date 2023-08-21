// Algoritmul descris mai jos foloseste o stiva efectiva pentru realizarea parcurgerii in adancime
// a grafului. Nota: pentru garantarea ordinii crescatoare, se va folosi un set.
#include <fstream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

int const NMAX = 105;
int n, m, x, u, v;
vector < int > ans;
vector < set < int > > adj(NMAX);
bool vis[NMAX];
stack < int > st;

int main() {
    fin >> n >> m >> x;
    while (m--) {
        fin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    st.push(x);
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            fout << node << ' ';
            vis[node] = true;
        }

        // Parcurgerea 'pe dos' garanteaza ordinea fireasca a raspunsului
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); it++)
            if (!vis[*it])
                st.push(*it);
    }
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}