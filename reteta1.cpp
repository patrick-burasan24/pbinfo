#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

ifstream fin("reteta1.in");
ofstream fout("reteta1.out");

int n, m, mat[16][21], tip[16], l[16], pret[21];
bitset<16> B;
float best = 1000000000;

inline void back(const int &k) {
    if (k == m + 1) {
        // Verificam daca avem o solutie valida
        // Restrictii: Avem toate medicamentele si le cumparam
        // DOAR o data
        bitset<21> N;
        float pret_curent = 0;
        for (int i = 1; i <= m; i++)
            if (B[i])
                for (int j = 1; j <= l[i]; j++) {
                    if (N[mat[i][j]]) return;
                    N[mat[i][j]] = 1;
                    if (tip[i] == 2)
                        pret_curent += ((float)pret[mat[i][j]] / 2.0);
                    else
                        pret_curent += pret[mat[i][j]];
                }
        for (int i = 1; i <= n; i++)
            if (!N[i]) return;
        if (pret_curent < best)
            best = pret_curent;
        return;
    }

    B[k] = 1;
    back(k + 1);
    B[k] = 0;
    back(k + 1);
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= m; i++) {
        fin >> tip[i] >> l[i];
        for (int j = 1; j <= l[i]; j++)
            fin >> mat[i][j];
    }

    for (int i = 1; i <= n; i++)
        fin >> pret[i];
    back(1);
    fout << fixed << setprecision(1) << best << '\n';
    fin.close();
    fout.close();
    return 0;
}