#include <fstream>
#include <queue>

using namespace std;

ifstream cin("taxe2.in");
ofstream cout("taxe2.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 105;
int const INF = 2e9;
int S, n, a[NMAX][NMAX], dp[NMAX][NMAX];

struct Coordonata {
    int x, y, cost;
    bool operator< (Coordonata A) const {
        return A.cost < cost;
    }
};

priority_queue < Coordonata > q;

void Citire() {
    int i, j;
    cin >> S >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
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
    Coordonata w;
    w.x = 1;
    w.y = 1;
    w.cost = a[1][1];
    dp[1][1] = a[1][1];
    q.push(w);
    while (!q.empty()) {
        r = q.top().x;
        c = q.top().y;
        q.pop();
        for (i = 0; i < 4; i++) {
            rr = r + di[i];
            cc = c + dj[i];
            if (a[rr][cc] != -1 && dp[rr][cc] > dp[r][c] + a[rr][cc]) {
                w.x = rr;
                w.y = cc;
                w.cost = dp[rr][cc] = dp[r][c] + a[rr][cc];
                q.push(w);
            }
        }
    }
}

void Afisare() {
    if (S - dp[n][n] < 0)
        cout << "-1\n";
    else
        cout << S - dp[n][n] << '\n';
    cin.close();
    cout.close();
}

int main() {
    Citire();
    Bordare();
    Init();
    Lee();
    Afisare();
    return 0;
}