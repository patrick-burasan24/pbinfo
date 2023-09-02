#include <fstream>
#include <queue>
#include <deque>

using namespace std;

ifstream cin("rover.in");
ofstream cout("rover.out");

int const di[] = {-1, 0, 1,  0};
int const dj[] = { 0, 1, 0, -1};

int const NMAX = 505;
int const INF = 2e9;
int cerinta, st, dr, mid, p, n, g, mat[NMAX][NMAX], dp[NMAX][NMAX];

void Citire() {
    cin >> cerinta;
    cin >> n;
    if (cerinta == 1)
        cin >> g;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
}

void Initializare() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = INF;
}

inline bool Ok(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > n)
        return false;
    return true;
}

void Lee(int i, int j) {
    int new_i, new_j, cost;
    deque < pair < int, int > > q;
    q.push_back({i, j});
    dp[i][j] = 0;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop_front();
        for (int k = 0; k < 4; k++) {
            new_i = i + di[k];
            new_j = j + dj[k];
            if (Ok(new_i, new_j)) {
                cost = 0;
                if (mat[new_i][new_j] < g)
                    cost = 1;
                if (dp[new_i][new_j] > cost + dp[i][j]) {
                    dp[new_i][new_j] = cost + dp[i][j];
                    if (!q.empty() && dp[new_i][new_j] <= dp[q.front().first][q.front().second]) 
                        q.push_front({new_i, new_j});
                    else
                        q.push_back({new_i, new_j});
                }
            }
        }
    }
}

int main() {
    Citire();
    Initializare();
    if (cerinta == 1) {
        Lee(1, 1);
        cout << dp[n][n] << '\n';
    } else {
        st = 1;
        dr = 10000;
        while (st <= dr) {
            mid = st + (dr - st) / 2;
            g = mid;
            Lee(1, 1);
            if (dp[n][n] == 0) {
                p = mid;
                st = mid + 1;
            } else
                dr = mid - 1;
            Initializare();
        }
        cout << p << '\n';
    }
    cin.close();
    cout.close();
    return 0;
}