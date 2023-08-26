#include <fstream>
#include <queue>

using namespace std;

ifstream cin("labirint.in");
ofstream cout("labirint.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 1005;
int n, st, dr, mid, p, mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > n)
        return false;
    if (matriceFill[i][j])
        return false;
    return true;
}

void fill(int istart, int jstart) {
    if (mat[istart][jstart] > mid) return;
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    matriceFill[istart][jstart] = true;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] <= mid) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    st = 0;
    dr = 100000;
    while (st <= dr) {
        mid = (st + dr) >> 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                matriceFill[i][j] = false;
        fill(1, 1);
        if (matriceFill[n][n]) {
            p = mid;
            dr = mid - 1;
        } else
            st = mid + 1;
    }
    cout << p << '\n';
    cin.close();
    cout.close();
    return 0;
}