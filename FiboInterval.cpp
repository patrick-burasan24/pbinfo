#include <fstream>

using namespace std;

ifstream fin("fibointerval.in");
ofstream fout("fibointerval.out");

short int n, q, a, b, rez[505], fibo[1005][505];

int main() {
    fin >> n >> q;
    fibo[1][0] = 1;
    fibo[1][1] = 1;
    fibo[2][0] = 1;
    fibo[2][1] = 1;

    // Calculam fibonacci
    for (int i = 3; i <= n + 2; i++) {
        unsigned T = 0;
        fibo[i][0] = 0;
        for (int j = 1; j <= fibo[i - 1][0] || j <= fibo[i - 2][0]; j++, fibo[i][0]++) {
            fibo[i][j] += fibo[i - 1][j] + fibo[i - 2][j] + T;
            T = fibo[i][j] / 10;
            fibo[i][j] %= 10;
        }

        while (T) fibo[i][++fibo[i][0]] = T % 10, T /= 10;
    }

    while (q--) {
        fin >> a >> b;
        for (int i = fibo[a][0]; i > 0; i--) fout << fibo[a][i];
        fout << ' ';
        for (int i = fibo[b][0]; i > 0; i--) fout << fibo[b][i];
        fout << ' ';
        
        // Rezultatul se bazeaza pe observatia ca suma primilor k termeni fibonacci
        // este egala cu termenul fibonacci de pe pozitia k + 2 minus 1
        // Formal S(k) = F(k + 2) + 1;
        // Extinzand observatia la intervalul nostru definit de capetele l, r
        // S(l, r) = S(r) - S(l - 1) (sume partiale)
        // Inlocuind relatia anterioare (Formula lui Binet)
        // S(l, r) = F(r + 2) - F(l + 1)
        // Programul simuleaza aceasta relatie.
        rez[0] = fibo[b + 2][0];                    /* Copiem in rez termenul r + 2 */
        for (int i = 1; i <= fibo[b + 2][0]; i++)
            rez[i] = fibo[b + 2][i];
        
        unsigned T = 0;
        for (int i = 1; i <= rez[0]; i++) {         /* Facem scaderea efectiva */
            rez[i] -= (fibo[a + 1][i] + T);
            if (rez[i] < 0) T = 1; else T = 0;
            if (T) rez[i] += 10;
        }

        while (rez[0] > 1 && !rez[rez[0]]) rez[0]--;
        for (int i = rez[0]; i > 0; i--) fout << rez[i];
        fout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}