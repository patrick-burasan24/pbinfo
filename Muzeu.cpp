#include <fstream>
typedef int Coada[63000];

using namespace std;

ifstream fin("muzeu.in");
ofstream fout("muzeu.out");

int const x[] = {0, 1, 0, -1},
          y[] = {-1, 0, 1, 0};

int N, st, dr, d[251][251];
char a[251][251];
Coada row, col;

int main() {
    fin >> N;
    st = 1;
    dr = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            fin >> a[i][j];
            if (a[i][j] == 'P') {
                dr++;
                row[dr] = i;
                col[dr] = j;
                d[i][j]++;
                a[i][j] = '#';
            } else if (a[i][j] == '#')
                d[i][j]--;
        }
    while (st <= dr) {
        int r = row[st];
        int c = col[st];
        st++;
        for (int i = 0; i < 4; i++) {
            int rr = r + y[i];
            int cc = c + x[i];
            if (rr >= 1 && rr <= N && cc >= 1 && cc <= N && a[rr][cc] != '#') {
                a[rr][cc] = '#';
                dr++;
                row[dr] = rr;
                col[dr] = cc;
                d[rr][cc] = d[r][c] + 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            fout << d[i][j] - 1 << ' ';
        fout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}