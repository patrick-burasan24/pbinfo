#include <fstream>
#include <queue>

using namespace std;

ifstream cin("gigelajungeacasa.in");
ofstream cout("gigelajungeacasa.out");

int const di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int const dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int const NMAX = 1005;
int N, M, K, X1, Y1, X2, Y2, XY, YY, XB, YB, X, Y, d[NMAX][NMAX];
bool mat[NMAX][NMAX], vis[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > N || j > M)
        return false;
    if (mat[i][j] || vis[i][j])
        return false;
    return true;
}

int Lee(int istart, int jstart) {
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    vis[istart][jstart] = true;
    d[istart][jstart] = 0;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if (r == X2 && c == Y2) 
            return d[r][c];
        for (int i = 0; i < 8; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc)) {
                Q.push(make_pair(rr, cc));
                vis[rr][cc] = true;
                d[rr][cc] = d[r][c] + 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M >> K;
    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> XY >> YY >> XB >> YB;
    mat[XY][YY] = mat[XB][YB] = true;
    while (K--) {
        cin >> X >> Y;
        mat[X][Y] = true;
    }
    cout << Lee(X1, Y1) << '\n';
    cin.close();
    cout.close();
    return 0;
}