#include <fstream>
#include <deque>

using namespace std;

ifstream cin("taxa.in");
ofstream cout("taxa.out");

int const di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int const dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int const NMAX = 1005;
int const INF = 2e9;
int N, M, xs, ys, xf, yf, a[NMAX][NMAX], dp[NMAX][NMAX];
deque < pair < int, int > > dq;

void Citire() {
    int i, j;
    cin >> N >> M >> xs >> ys >> xf >> yf;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++)
            cin >> a[i][j];
}

void Bordare() {
    int i, j;
    for (i = 0; i <= N + 1; i++)
        a[i][0] = a[i][M + 1] = -1;
    for (j = 0; j <= M + 1; j++)
        a[0][j] = a[N + 1][j] = -1;
}

void Init() {
    int i, j;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++)
            dp[i][j] = INF;
}

void Lee() {
    int r, c, rr, cc, i, cost;
    dq.push_back({xs, ys});
    dp[xs][ys] = 0;
    while (!dq.empty()) {
        r = dq.front().first;
        c = dq.front().second;
        dq.pop_front();
        for (i = 0; i < 8; i++) {
            rr = r + di[i];
            cc = c + dj[i];
            cost = 0;
            if (a[rr][cc] != a[r][c])
                cost = a[rr][cc] * a[r][c];
            if (a[rr][cc] != -1 && dp[rr][cc] > dp[r][c] + cost) {
                dp[rr][cc] = dp[r][c] + cost;
                if (!dq.empty() && dp[rr][cc] <= dp[dq.front().first][dq.front().second])
                    dq.push_front({rr, cc});
                else
                    dq.push_back({rr, cc});
            }
        }
    }
}

void Afisare() {
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << dp[xf][yf] << '\n';
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