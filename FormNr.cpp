#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 256;

char s[NMAX];

int solve(char *s) {
    int sol = 0;
    for (size_t i = 0; s[i]; i++) {
        if (s[i] >= '1' && s[i] <= '9') {
            int nr = 0;
            int j = i;
            while (s[j] && s[j] >= '0' && s[j] <= '9') {
                nr = nr * 10 + (s[j] - '0');
                j++;
            }
            sol += nr;
            i = j - 1;
        }
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.getline(s, NMAX);
    cout << solve(s) << '\n';
    return 0;
}