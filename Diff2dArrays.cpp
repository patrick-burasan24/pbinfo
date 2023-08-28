#include <iostream>

using namespace std;

int const NMAX = 505;
int N, Q, l1, c1, l2, c2, x, a[NMAX][NMAX], b[NMAX][NMAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];
    cin >> Q;
    while (Q--) {
        cin >> l1 >> c1 >> l2 >> c2 >> x;
        b[l1][c1] += x;
        b[l2 + 1][c1] -= x;
        b[l1][c2 + 1] -= x;
        b[l2 + 1][c2 + 1] += x;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            a[i][j] += b[i][j];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}