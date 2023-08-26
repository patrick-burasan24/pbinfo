#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

ifstream cin("insule.in");
ofstream cout("insule.out");

int const x[] = {0, 1, 0, -1};
int const y[] = {-1, 0, 1, 0};

int N, M, fr[4], mat[105][105], d[105][105];
bool vis[105][105];
char s[105];

inline void afisMat() {
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}

inline bool ok1(int const &i, int const &j) {
    if (i < 0 || j < 0 || i >= N || j >= M)
        return false;
    if (vis[i][j])
        return false;
    return true;
}

inline bool ok2(int const &i, int const &j) {
    if (i < 0 || j < 0 || i >= N || j >= M) 
        return false;
    if (vis[i][j])
        return false;
    if (mat[i][j] == 1 || mat[i][j] == 3)
        return false;
    return true;
}

void Fill(int const &row, int const &col) {
    queue < pair < int, int > > q;
    q.push(make_pair(row, col));
    vis[row][col] = true;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + y[i];
            int cc = c + x[i];
            if (ok1(rr, cc) && mat[r][c] == mat[rr][cc]) {
                vis[rr][cc] = true;
                q.push(make_pair(rr, cc));
            }
        }
    }
}

void Lee() {
    queue < pair < int, int > > q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 1) {
                vis[i][j] = true;
                q.push(make_pair(i, j));
                
            } else 
                vis[i][j] = false;
        }
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        // cout << "Celula: " << '(' << r << ',' << c << ')' << '\n';
        // cout << "Dist: " << d[r][c] << '\n'; 
        q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = r + y[i];
            int cc = c + x[i];
            if (ok2(rr, cc)) {
                
                if (mat[rr][cc] == 2 && d[r][c] != 0) {
                    cout << d[r][c] << '\n';
                    return;
                } else if (mat[rr][cc] == 2 && d[r][c] == 0)
                    continue;
                vis[rr][cc] = true;
                d[rr][cc] = d[r][c] + 1;
                q.push(make_pair(rr, cc));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        cin.getline(s, 105);
        for (int j = 0; j < M; j++)
            mat[i][j] = s[j] - '0';
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                fr[mat[i][j]]++;
                Fill(i, j);
            }
        }
    for (int i = 1; i < 4; i++)
        cout << fr[i] << ' ';
    // afisMat();
    Lee();
    cin.close();
    cout.close();
    return 0;
}