#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 256;
constexpr char sep[] = ".,!?";

int n;
char s[NMAX];

void solve() {
    cin.getline(s, NMAX);
    for (int i = 0; s[i]; i++)
        if (strchr(sep, s[i]) != nullptr && s[i + 1] != '\0') {
            char t[NMAX];
            strcpy(t, s + i + 1);
            strcpy(s + i, t);
            i--;
        }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin.ignore();
    while (n--)
        solve();
    return 0;
}