#include <fstream>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

ifstream cin("sahara.in");
ofstream cout("sahara.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 1005;
int N, M, Q, q, T, r1, r2, c1, c2, arie, arie_maxima, mars[NMAX][NMAX], mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > N || j > M)
        return false;
    if (matriceFill[i][j])
        return false;
    return true;
}

void fill(int istart, int jstart) {
    queue < pair < int, int > > coada;
    coada.push(make_pair(istart, jstart));
    matriceFill[istart][jstart] = true;
    arie++;
    while (!coada.empty()) {
        int r = coada.front().first;
        int c = coada.front().second;
        coada.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] >= Q) {
                coada.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
                arie++;
            }
        }
    }
}

int main() {
    cin >> N >> M >> Q >> T;
    while (T--) {
        cin >> r1 >> c1 >> r2 >> c2 >> q;
        mars[r1][c1] += q;
        mars[r2 + 1][c1] -= q;
        mars[r1][c2 + 1] -= q;
        mars[r2 + 1][c2 + 1] += q;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            mars[i][j] += mars[i - 1][j] + mars[i][j - 1] - mars[i - 1][j - 1];
            mat[i][j] += mars[i][j];
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (!matriceFill[i][j] && mat[i][j] >= Q) {
                arie = 0;
                fill(i, j);
                if (arie > arie_maxima)
                    arie_maxima = arie;
            }
    cout << arie_maxima << '\n';
    cin.close();
    cout.close();
    return 0;
}