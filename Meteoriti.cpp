#include <fstream>
#include <queue>

using namespace std;

ifstream cin("meteoriti.in");
ofstream cout("meteoriti.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 2005;
int N, M, R, r1, r2, c1, c2, C, k, maxi, aria, aria_maxima, mat[NMAX][NMAX], mars[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > N || j > M)
        return false;
    if (matriceFill[i][j])
        return false;
    return true;
}

void fill(int istart, int jstart) {
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    matriceFill[istart][jstart] = true;
    aria++;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] == mat[r][c]) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
                aria++;
            }
        }
    }
}

int main() {
    cin >> N >> M >> R;
    while (R--) {
        cin >> r1 >> c1 >> r2 >> c2 >> C;
        mars[r1][c1] += C;
        mars[r2 + 1][c1] -= C;
        mars[r1][c2 + 1] -= C;
        mars[r2 + 1][c2 + 1] += C;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            mars[i][j] += mars[i - 1][j] + mars[i][j - 1] - mars[i - 1][j - 1];
            mat[i][j] += mars[i][j];
            if (!mat[i][j])
                k++;
            maxi = max(maxi, mat[i][j]);
        }
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= M; j++)
            if (!matriceFill[i][j] && mat[i][j] == maxi) {
                aria = 0;
                fill(i, j);
                aria_maxima = max(aria_maxima, aria);
            }
    cout << aria_maxima << ' ' << k << '\n';
    cin.close();
    cout.close();
    return 0;
}