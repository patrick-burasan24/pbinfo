#include <fstream>
#include <queue>

using namespace std;

ifstream cin("amongus.in");
ofstream cout("amongus.out");

int const di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int const dj[] = {0, 1, 0, -1, -1, 1, -1, 1};

int const NMAX = 105;
int p, n, m, camere_sigure, portale, mat[NMAX][NMAX];
bool matriceFill[NMAX][NMAX];

inline void afisMat() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}

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
    if (mat[istart][jstart] == 2)
        portale++;
    mat[istart][jstart] = 3;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int rr = r + di[i];
            int cc = c + dj[i];
            if (ok(rr, cc) && mat[rr][cc] != 1) {
                Q.push(make_pair(rr, cc));
                matriceFill[rr][cc] = true;
                if (mat[rr][cc] == 2)
                    portale++;
                mat[rr][cc] = 3;
            }
        }
    }
}

int main() {
    cin >> p >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 0)
                camere_sigure++;
        }
    if (mat[1][1] == 1)
        cout << "misiune esuata\n";
    else {
        fill(1, 1);
        if (p == 1)
            cout << camere_sigure << '\n';
        else if (p == 2)
            afisMat();
        else
            cout << portale << '\n';
    }
    cin.close();
    cout.close();
    return 0;
}