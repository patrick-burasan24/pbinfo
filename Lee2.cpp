#include <iostream>
#include <queue>

using namespace std;

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 1505;
int const INF = 2e9;
int n, X, Y, Z, T, a[NMAX][NMAX], dp[NMAX][NMAX];

struct Coordonata {
    int x, y, cost;
    bool operator< (Coordonata A) const {
        return A.cost < cost;
    }
};

priority_queue < Coordonata > q;

void Citire() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i, j;
    cin >> n >> X >> Y >> Z >> T;
    for (j = 1; j <= n; j++)
        cin >> a[1][j];
    for (i = 2; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 1 + (a[i-1][j-1] * X + a[i-1][j] * Y + a[i-1][j+1] * Z) % T;
}

void Bordare() {
    int i;
    for (i = 0; i <= n + 1; i++)
        a[i][0] = a[0][i] = a[i][n + 1] = a[n + 1][i] = -1;
}

void Init() {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            dp[i][j] = INF;
}

void Lee() {
    int r, c, rr, cc, i;
    Coordonata e;
    e.x = 1;
    e.y = 1;
    e.cost = a[1][1];
    dp[1][1] = a[1][1];
    q.push(e);
    while (!q.empty()) {
        r = q.top().x;
        c = q.top().y;
        q.pop();
        for (i = 0; i < 4; i++) {
            rr = r + di[i];
            cc = c + dj[i];
            if (a[rr][cc] != -1 && dp[rr][cc] > dp[r][c] + a[rr][cc]) {
                e.x = rr;
                e.y = cc;
                e.cost = dp[rr][cc] = dp[r][c] + a[rr][cc];
                q.push(e);
            }
        }
    }
}

void Afisare() {
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << dp[n][n] << '\n';
}

int main() {
    Citire();
    Bordare();
    Init();
    Lee();
    Afisare();
    return 0;
}