#include <fstream>
#include <queue>

using namespace std;

ifstream cin("oaste.in");
ofstream cout("oaste.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 105;
int n, m, counter, max_soldiers, best, region, current_i, current_j, best_i, best_j, mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    if (matriceFill[i][j])
        return false;
    return true;
}

void fill(int istart, int jstart) {
    queue < pair < int, int > > Q;
    Q.push(make_pair(istart, jstart));
    matriceFill[istart][jstart] = true;
    best = mat[istart][jstart];
    current_i = istart;
    current_j = jstart;
    counter += mat[istart][jstart];
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if (mat[r][c] > best) {
            best = mat[r][c];
            current_i = r;
            current_j = c;
        } else if (mat[r][c] == best && r < current_i) {
            current_i = r;
            current_j = c;
        } else if (mat[r][c] == best && r == current_i && c < current_j) {
            current_j = c;
        }
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] != 0) {
                counter += mat[rr][cc];
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!matriceFill[i][j] && mat[i][j]) {
                counter = 0;
                fill(i, j);
                if (counter > max_soldiers) {
                    max_soldiers = counter;
                    region = best;
                    best_i = current_i;
                    best_j = current_j;
                }
            }
    cout << region << ' ' << best_i << ' ' << best_j << '\n';
    cin.close();
    cout.close();
    return 0;
}