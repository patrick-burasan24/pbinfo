#include <iostream>

using namespace std;

int const NMAX = 10005;
int n, m, st, dr, maxi, a[NMAX], b[NMAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> st >> dr;
        b[st]++;
        b[dr + 1]--;
    }
    for (int i = 1; i <= NMAX; i++) {
        b[i] += b[i - 1];
        a[i] += b[i];
        if (a[i] > maxi)
            maxi = a[i];
    }
    cout << maxi << '\n';
    return 0;
}