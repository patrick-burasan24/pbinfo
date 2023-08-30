#include <fstream>
#include <queue>

using namespace std;

ifstream cin("castel2.in");
ofstream cout("castel2.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 1005;
int n, m, k, d[NMAX][NMAX];
char mat[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    return true;
}

int lee(int istart, int jstart) {
    if (mat[istart][jstart] != '-')
        return -1;
    queue < pair < int, int > > q;
    q.push({istart, jstart});
    d[istart][jstart] = 1;
    mat[istart][jstart] = '*';
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r == n && c == m)
            return d[r][c];
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] == '-') {
                q.push({rr, cc});
                d[rr][cc] = d[r][c] + 1;
                mat[rr][cc] = '*';
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> k;
    queue < pair < int, int > > q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'Z') {
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] == '-') {
                d[rr][cc] = d[r][c] + 1;
                if (d[rr][cc] > k)
                    continue;
                q.push({rr, cc});
                mat[rr][cc] = '*';
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         cout << mat[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << lee(1, 1) << '\n';
    cin.close();
    cout.close();
    return 0;
}