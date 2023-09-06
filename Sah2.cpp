#include <fstream>
#include <queue>
using namespace std;

ifstream cin("sah2.in");
ofstream cout("sah2.out");

const int cal_i[] = {-2, -2, -1, 1, 2,  2,  1, -1};
const int cal_j[] = {-1,  1,  2, 2, 1, -1, -2, -2};
const int di[] = {-1, -1, 1,  1};
const int dj[] = {-1,  1, 1, -1};

const int NMAX = 505;
const int INF = 1000;
int n, r0, c0, r1, c1, dp[NMAX][NMAX], miscariCal[NMAX][NMAX];
char t[NMAX][NMAX];

struct Punct {
    int row, col, moves;
    bool operator< (Punct A) const {
        return moves < A.moves;
    }
};

void Citire() {
    cin >> n >> r0 >> c0 >> r1 >> c1;
    for (int i = 1; i <= n; i++)
        cin >> (t[i] + 1);
}

void Init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = INF, miscariCal[i][j] = -1;
}

inline bool Ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > n)
        return false;
    if (t[i][j] == '1')
        return false;
    return true;
}

void Lee(int i, int j) {
    int noul_i, noul_j, miscari;
    queue<Punct> q;
    Punct w;
    w.row = i;
    w.col = j;
    w.moves = 2;
    q.push(w);
    dp[i][j] = 0;
    miscariCal[i][j] = 2;
    while (!q.empty()) {
        i = q.front().row;
        j = q.front().col;
        miscari = q.front().moves;
        q.pop();

        if (i == r1 && j == c1) {
            cout << dp[r1][c1] << '\n';
            return;
        }
        
        if (miscari > 0)
            for (int k = 0; k < 8; k++) {
                noul_i = i + cal_i[k];
                noul_j = j + cal_j[k];
                if (Ok(noul_i, noul_j) && (dp[noul_i][noul_j] > 1 + dp[i][j] ||
                    miscariCal[noul_i][noul_j] < miscari - 1)) {
                    dp[noul_i][noul_j] = 1 + dp[i][j];
                    miscariCal[noul_i][noul_j] = miscari - 1;
                    w.row = noul_i;
                    w.col = noul_j;
                    w.moves = miscari - 1;
                    q.push(w);
                }
            }
        
        for (int k = 0; k < 4; k++) {
            for (int pas = 1; ; pas++) {
                noul_i = i + di[k] * pas;
                noul_j = j + dj[k] * pas;
                
                if (!Ok(noul_i, noul_j)) break;

                if (dp[noul_i][noul_j] > 1 + dp[i][j] || 
                    miscariCal[noul_i][noul_j] < miscari) {
                    dp[noul_i][noul_j] = 1 + dp[i][j];
                    miscariCal[noul_i][noul_j] = miscari;
                    w.row = noul_i;
                    w.col = noul_j;
                    w.moves = miscari;
                    q.push(w);
                }
            }
        }
    }
}

signed main() {
    Citire();
    Init();
    Lee(r0, c0);
    cin.close();
    cout.close();
    return 0;
}