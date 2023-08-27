#include <fstream>
#include <queue>

using namespace std;

ifstream cin("tsunami.in");
ofstream cout("tsunami.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 1005;
int n, m, cnt, h, mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    if (matriceFill[i][j])
        return false;
    return true;
}

void fill(int istart, int jstart) {
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    matriceFill[istart][jstart] = true;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if (mat[r][c] > 0 && mat[r][c] < h)
            cnt++;
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] < h) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!matriceFill[i][j] && !mat[i][j]) 
                fill(i, j);
    cout << cnt << '\n';
    cin.close();
    cout.close();
    return 0;
}