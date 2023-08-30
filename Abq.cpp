#include <fstream>
#include <queue>

using namespace std;

ifstream cin("abq.in");
ofstream cout("abq.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 205;
int n, m, q, xs, ys, xf, yf, d[NMAX][NMAX];
bool vis[NMAX][NMAX], mat[NMAX][NMAX];

void resetare() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            vis[i][j] = false;
}

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    if (mat[i][j] || vis[i][j])
        return false;
    return true;
}

int Lee(int istart, int jstart) {
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    vis[istart][jstart] = true;
    d[istart][jstart] = 1;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if (r == xf && c == yf) 
            return d[r][c];
        for (int i = 0; i < 4; i++) {
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'b')
                mat[i][j] = true;
        }
    cin >> q;
    while (q--) {
        resetare();
        cin >> xs >> ys >> xf >> yf;
        if (mat[xs][ys] || mat[xf][yf])
            cout << "-1\n";
        else
            cout << Lee(xs, ys) << '\n';
    }
    cin.close();
    cout.close();
    return 0;   
}