#include <fstream>
#include <queue>

using namespace std;

ifstream cin("harta1.in");
ofstream cout("harta1.out");

int const di[] = {-1, 0, 1, 0};
int const dj[] = {0, 1, 0, -1};

int const NMAX = 105;
int N, M, K, p, maxi, cnt, fr[11], mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline bool ok(int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= M)
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
            if (ok(rr, cc) && mat[rr][cc] == mat[r][c]) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
            }
        }
    }
}

int main() {
    cin >> p >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 0)
                cnt++;
        }
    if (p == 1) 
        cout << cnt << '\n';
    else {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!matriceFill[i][j] && mat[i][j] != 0) {
                    fr[mat[i][j]]++;
                    if (fr[mat[i][j]] > maxi)
                        maxi = fr[mat[i][j]];
                    fill(i, j);
                }
        for (int i = 1; i <= K; i++)
            if (fr[i] == maxi)
                cout << i << ' ';
        cout << '\n';
    }
    cin.close();
    cout.close();
    return 0;
}