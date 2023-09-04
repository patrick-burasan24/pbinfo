#include <fstream>
#include <queue>

using namespace std;

ifstream cin("ferma1.in");
ofstream cout("ferma1.out");

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

const int NMAX = 55;
int n, m, r0, c0;
char mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

void Citire() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'R') {
                r0 = i;
                c0 = j;
            }
        }
}

void Afisare() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j];
        cout << '\n';
    }
}

inline bool Ok(int i, int j) {
    if (i < 2 || j < 2 || i > n - 1 || j > m - 1)
        return false;
    if (matriceFill[i][j])
        return false;
    for (int linie = i - 1; linie <= i + 1; linie++)
        for (int coloana = j - 1; coloana <= j + 1; coloana++)
            if (mat[linie][coloana] == '+')
                return false;
    return true;
}

void Colorare(int i, int j) {
    for (int linie = i - 1; linie <= i + 1; linie++)
        for (int coloana = j - 1; coloana <= j + 1; coloana++)
            mat[linie][coloana] = '*';
}

void Lee(int i, int j) {
    int noul_i, noul_j;
    queue < pair < int, int > > q;
    q.push({i, j});
    matriceFill[i][j] = true;
    Colorare(i, j);
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            noul_i = i + di[k];
            noul_j = j + dj[k];
            if (Ok(noul_i, noul_j)) {
                q.push({noul_i, noul_j});
                matriceFill[noul_i][noul_j] = true;
                Colorare(noul_i, noul_j);
            }
        }
    }
}

int main() {
    Citire();
    if (Ok(r0, c0))
        Lee(r0, c0);
    Afisare();
    cin.close();
    cout.close();
    return 0;
}