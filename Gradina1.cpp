#include <fstream>
#include <queue>

using namespace std;

ifstream cin("gradina1.in");
ofstream cout("gradina1.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 55;
int const SMAX = 105;
int n, m, a, amax, s, v[SMAX], mat[NMAX][NMAX], umid[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    if (matriceFill[i][j])
        return false;
    return true;
}

void fill(int istart, int jstart, int k) {
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    matriceFill[istart][jstart] = true;
    a++;
    // cout << "\nSpecia curenta: " << k << '\n';
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        // cout << "Celula: (" << r << ',' << c << ")\n";
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] == 0 && umid[rr][cc] >= v[k]) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
                a++;
            } else if (ok(rr, cc) && mat[rr][cc] == k) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
                a++;
            }
                
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= s; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> umid[i][j];
    for (int k = 1; k <= s; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                matriceFill[i][j] = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!matriceFill[i][j] && mat[i][j] == 0 && umid[i][j] >= v[k]) {
                    a = 0;
                    fill(i, j, k);
                    if (a > amax)
                        amax = a;
                } else if (!matriceFill[i][j] && mat[i][j] == k) {
                    a = 0;
                    fill(i, j, k);
                    if (a > amax)
                        amax = a;
                }
    }
    cout << amax << endl;
    cin.close();
    cout.close();
    return 0;
}