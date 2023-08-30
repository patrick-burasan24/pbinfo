#include <fstream>
#include <queue>
#include <bitset>

using namespace std;

ifstream cin("rj.in");
ofstream cout("rj.out");

int const di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int const dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int const NMAX = 105;
int N, M, mini, r0, c0, r1, c1, r2, c2, dp1[NMAX][NMAX], dp2[NMAX][NMAX];
char mat[NMAX][NMAX];
bool vis[NMAX][NMAX];

void resetare() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            vis[i][j] = false;
}

inline bool ok(int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= M)
        return false;
    return true;
}

int main() {
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; i++)
        cin.getline(mat[i], NMAX);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (mat[i][j] == 'R') {
                r1 = i;
                c1 = j;
            } else if (mat[i][j] == 'J') {
                r2 = i;
                c2 = j;
            }
    queue < pair < int, int > > q;
    q.push({r1, c1});
    vis[r1][c1] = true;
    dp1[r1][c1] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] == ' ' && !vis[rr][cc]) {
                q.push({rr, cc});
                vis[rr][cc] = true;
                dp1[rr][cc] = dp1[r][c] + 1;
            }
        }
    }
    resetare();
    q.push({r2, c2});
    vis[r2][c2] = true;
    dp2[r2][c2] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] == ' ' && !vis[rr][cc]) {
                q.push({rr, cc});
                vis[rr][cc] = true;
                dp2[rr][cc] = dp2[r][c] + 1;
            }
        }
    }
    mini = 999999999;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (dp1[i][j] && dp1[i][j] == dp2[i][j] && dp1[i][j] < mini) {
                mini = dp1[i][j];
                r0 = i;
                c0 = j;
            }
    cout << mini << ' ' << r0 + 1 << ' ' << c0 + 1 << '\n';
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++)
    //         cout << mat[i][j];
    //     cout << '\n'; 
    // }
    cin.close();
    cout.close();
    return 0;
}