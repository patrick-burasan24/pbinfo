#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 101;

char s[NMAX];

void solve() {
    bool foundWord = false;
    char *p = strtok(s, " ");
    char sol[NMAX]{ '\0' };
    while (p != nullptr) {
        if (!(strlen(p) & 1)) {
            foundWord = true;
            strcat(sol, "#");
        } else 
            strcat(sol, p);
        strcat(sol, " ");
        p = strtok(nullptr, " ");
    }
    if (!foundWord)
        cout << "nu exista\n";
    else {
        strcpy(s, sol);
        cout << s << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.getline(s, NMAX);
    solve();
    return 0;
}