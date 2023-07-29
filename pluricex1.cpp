#include <fstream>
#include <bitset>

using namespace std;

ifstream fin("pluricex1.in");
ofstream fout("pluricex1.out");

int n, k, D, mat[23][11], l[11];
bitset<23> B;

inline bool valid() {
    bitset<11> N;
    for (int i = 1; i <= n; i++)
        if (B[i])
            for (int j = 1; j <= l[i]; j++)
                N[mat[i][j]] = 1;
    for (int i = 1; i <= D; i++)
        if (!N[i]) return 0;
    return 1;
}

inline void back(const int &y, const int &cnt) {
    if (cnt > k) return;
    if (y == n + 1) {
        if (cnt == k && valid()) {
            for (int i = 1; i <= n; i++)
                if (B[i])
                    fout << i << ' ';
            fout << '\n';
        }
        return;
    }

    B[y] = 1;
    back(y + 1, cnt + 1);
    B[y] = 0;
    back(y + 1, cnt);
}

int main() {
    fin >> n >> k >> D;
    for (int i = 1; i <= n; i++) {
        fin >> l[i];
        for (int j = 1; j <= l[i]; j++)
            fin >> mat[i][j];
    }
    back(1, 0);
    fin.close();
    fout.close();
    return 0;
}