#include <fstream>
#include <queue>

using namespace std;

ifstream cin("ubuph.in");
ofstream cout("ubuph.out");

const int di[] = {-1, 0, 1,  0};
const int dj[] = { 0, 1, 0, -1};

const int NMAX = 1005;
const int INF = 2e9;
int n, m, i_start, j_start, i_final, j_final, mat[NMAX][NMAX], dp[NMAX][NMAX];

struct Punct {
    int row, col, cost;
    bool operator< (Punct A) const {
        return A.cost < cost;
    }
};

void Citire() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    cin >> i_start >> j_start >> i_final >> j_final;
}

void Init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = INF;
}

void Bordare() {
    for (int i = 0; i <= n + 1; i++)
        mat[i][0] = mat[i][m + 1] = -1;
    for (int j = 0; j <= m + 1; j++)
        mat[0][j] = mat[n + 1][j] = -1;
}

void Lee(int i, int j) {
    int noul_i, noul_j;
    priority_queue<Punct> q;
    Punct w;
    w.row = i;
    w.col = j;
    w.cost = mat[i][j];
    dp[i][j] = mat[i][j];
    q.push(w);
    while (!q.empty()) {
        i = q.top().row;
        j = q.top().col;
        q.pop();
        for (int k = 0; k < 4; k++) {
            noul_i = i + di[k];
            noul_j = j + dj[k];
            if (mat[noul_i][noul_j] != -1 && dp[noul_i][noul_j] > mat[noul_i][noul_j] + dp[i][j]) {
                dp[noul_i][noul_j] = mat[noul_i][noul_j] + dp[i][j];
                w.row = noul_i;
                w.col = noul_j;
                w.cost = dp[noul_i][noul_j];
                q.push(w);
            }
        }
    }
}

void Afis() {
    cout << dp[i_final][j_final] << '\n';
}

int main() {
    Citire();
    Init();
    Bordare();
    Lee(i_start, j_start);
    Afis();
    cin.close();
    cout.close();
    return 0;
}