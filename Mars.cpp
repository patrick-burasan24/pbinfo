#include <iostream>

using namespace std;

int const NMAX = 200005;
int n, m, st, dr, x;
long long a[NMAX], b[NMAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> st >> dr >> x;
        b[st] += x;
        b[dr + 1] -= x;
    }
    a[1] = b[1];
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + b[i];
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}