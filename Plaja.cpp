#include <fstream>

using namespace std;

ifstream cin("plaja.in");
ofstream cout("plaja.out");

typedef int Stiva[1005];

Stiva st;
const int NMAX = 1005;
int n, m, top, maxi, stanga[NMAX], dreapta[NMAX], s[NMAX][NMAX];
char t[NMAX][NMAX];

void Citire() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> (t[i] + 1);
}

void Rezolvare() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (t[i][j] == '1')
                s[i][j] = 0;
            else
                s[i][j] = 1 + s[i - 1][j];
    // Prelucram pentru fiecare linie maximul posibil
    maxi = -1;
    for (int i = 1; i <= n; i++) {
        s[i][0] = s[i][m + 1] = -1;
        top = 0;
        st[++top] = 0;
        for (int j = 1; j <= m; j++) {
            while (s[i][st[top]] >= s[i][j])
                top--;
            stanga[j] = j - st[top];
            st[++top] = j;
        }
        top = 0;
        st[++top] = m + 1;
        for (int j = m; j >= 1; j--) {
            while (s[i][st[top]] >= s[i][j])
                top--;
            dreapta[j] = st[top] - j;
            st[++top] = j;
        }
        for (int j = 1; j <= m; j++)
            maxi = max(maxi, s[i][j] * (stanga[j] + dreapta[j] - 1));
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