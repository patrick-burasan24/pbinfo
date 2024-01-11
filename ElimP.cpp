#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 255;

int p;
char s[NMAX + 1];

void solve() {
    int n = strlen(s);
    for (int i = 0; i <= n - p; i++) {
        char t[NMAX + 1];
        strcpy(t, s);
        char temp[NMAX + 1];
        strcpy(temp, t + i + p);
        strcpy(t + i, temp);
        cout << t << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> p;
    cin.ignore();
    cin.getline(s, NMAX + 1);
    solve();
    return 0;
}