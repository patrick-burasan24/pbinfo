#include <fstream>
#include <queue>

using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

int const x[] = {0, 1, 0, -1},
          y[] = {-1, 0, 1, 0};
int N, M, X1, Y1, X2, Y2, dist[176][176];
bool mat[176][176];
queue < pair < int, int > > Q;

int main() {
    fin >> N >> M;
    while (M--) {
        fin >> X1 >> Y1;
        mat[Y1][X1] = true;
    }
    fin >> X1 >> Y1 >> X2 >> Y2;
    Q.push({ Y1, X1 });
    mat[Y1][X1] = true;
    dist[Y1][X1] = 1;
    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if (r == Y2 && c == X2) 
        for (int i = 0; i < 4; i++) {
            fout << dist[Y2][X2] << '\n';
            break;
        }
        for (int i = 0; i < 4; i++) {
            int rr = r + y[i];
            int cc = c + x[i];
            if (rr >= 1 && rr <= N && cc >= 1 && cc <= N && !mat[rr][cc]) {
                mat[rr][cc] = true;
                Q.push({ rr, cc });
                dist[rr][cc] = dist[r][c] + 1;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}