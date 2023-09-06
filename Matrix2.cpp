#include <fstream>

using namespace std;

ifstream cin("matrix2.in");
ofstream cout("matrix2.out");

const int NMAX = 1005;
int n, m, top, maxi, stg[NMAX], drp[NMAX], st[NMAX], mat[NMAX][NMAX], s[NMAX][NMAX];

void Citire() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
}

void Rezolvare() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mat[i][j] == 1)
                s[i][j] = 0;
            else
                s[i][j] = 1 + s[i - 1][j];
    maxi = -1;
    for (int i = 1; i <= n; i++) {
        s[i][0] = s[i][m + 1] = -1;
        top = 0;
        st[++top] = 0;
        for (int j = 1; j <= m; j++) {
            while (s[i][st[top]] >= s[i][j])
                top--;
            stg[j] = j - st[top];
            st[++top] = j;
        }
        top = 0;
        st[++top] = m + 1;
        for (int j = m; j >= 1; j--) {
            while (s[i][st[top]] >= s[i][j])
                top--;
            drp[j] = st[top] - j;
            st[++top] = j;
        }
        for (int j = 1; j <= m; j++)
            maxi = max(maxi, s[i][j] * (stg[j] + drp[j] - 1));
    }
}

void Afisare() {
    cout << maxi << '\n';
}

int main() {
    Citire();
    Rezolvare();
    Afisare();
    cin.close();
    cout.close();
    return 0;
}