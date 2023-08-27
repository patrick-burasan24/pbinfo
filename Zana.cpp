#include <fstream>
#include <queue>

using namespace std;

ifstream cin("zana.in");
ofstream cout("zana.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 185;
int n, m, k, x, y, n1, n2, mat[NMAX][NMAX];
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
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc)) {
                if (mat[rr][cc] != 0) {
                    matriceFill[rr][cc] = true;
                    if (mat[rr][cc] > n1) {
                        n1 = mat[rr][cc];
                        n2 = 1;
                        // cout << "MAXIM! Celula: (" << rr << ',' << cc << ")\n";
                    } else if (mat[rr][cc] == n1) {
                        n2++;
                        // cout << "INC! Celula: (" << rr << ',' << cc << ")\n";
                    }
                } else {
                    Q.push(make_pair(rr, cc));
                    matriceFill[rr][cc] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    while (k--) {
        cin >> x >> y;
        mat[x][y]++;
    }
    if (mat[1][1] != 0)
        cout << mat[1][1] << ' ' << 1 << '\n';
    else {
        fill(1, 1);
        cout << n1 << '\n' << n2 << '\n';
    }
    cin.close();
    cout.close();
    return 0;
}