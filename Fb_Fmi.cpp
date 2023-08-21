#include <fstream>
typedef int Coada[1001];

using namespace std;

ifstream fin("fb_fmi.in");
ofstream fout("fb_fmi.out");

int n, m, u, v, k, cnt, st, dr, bad[1001], friends[1001], adj[1001][1001];
Coada Q;

int main() {
    fin >> n >> m >> k;
    while (m--) {
        fin >> u >> v;
        // Daca nu exista o prietenie intre cei doi (formal, nu exista o muchie)
        // crestem gradul (in cazul nostru friends) de nodul u si v.
        if (!adj[u][v]) {
            friends[u]++;
            friends[v]++;
        }
        adj[u][v] = adj[v][u] = 1;
    }
    // Folosindu-ne de o structura de tip coada vom introduce initial toate nodurile
    // cu un grad <= k, apoi pana coada devine vida vom parcurge matricea de adiacenta
    // si vom elimina muchia dintre nodul cu gradul <= k si celelalte varfuri.
    // Daca friends[otherNode] devine < k il adaugam in coada.
    st = 1;
    dr = 0;
    for (int i = 1; i <= n; i++)
        if (friends[i] < k)
            Q[++dr] = i;
    while (st <= dr) {
        u = Q[st];
        bad[u] = 1;
        for (int i = 1; i <= n; i++) 
            if (adj[u][i] == 1) {
                friends[i]--;
                adj[u][i] = adj[i][u] = 0;
                if (friends[i] < k) 
                    Q[++dr] = i;
            }
        st++;
    }
    // Numaram toate elementele caracterizate de relatia bad[i] == 0
    for (int i = 1; i <= n; i++)
        if (!bad[i])
            cnt++;
    fout << cnt << '\n';
    if (cnt) {
        for (int i = 1; i <= n; i++)
            if (!bad[i])
                fout << i << ' ';
        fout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}