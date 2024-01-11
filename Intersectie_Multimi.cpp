#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 1000;
constexpr int NRMAX = 50;

int n;
char numereNaturale[NMAX + 1]{ '\0' };
char numereIntregi[NMAX + 1]{ '\0' };
char numereRationale[NMAX + 1]{ '\0' };
char numereIrationale[NMAX + 1]{ '\0' };
char s[NRMAX + 1];

void solve() {
    cin >> n;
    while (n--) {
        cin >> s;
        if (strstr(s, "...") != nullptr) {
            strcat(numereIrationale, s);
            strcat(numereIrationale, " ");
        } else if (strchr(s, '.') != nullptr) {
            strcat(numereRationale, s);
            strcat(numereRationale, " ");
        } else if (strchr(s, '-') != nullptr) {
            strcat(numereRationale, s);
            strcat(numereRationale, " ");
            strcat(numereIntregi, s);
            strcat(numereIntregi, " ");
        } else {
            strcat(numereRationale, s);
            strcat(numereRationale, " ");
            strcat(numereIntregi, s);
            strcat(numereIntregi, " ");
            strcat(numereNaturale, s);
            strcat(numereNaturale, " ");
        }
    }
    if (!strlen(numereNaturale)) {
        cout << "Multime vida\n";
    } else {
        cout << numereNaturale << '\n';
    }
    if (!strlen(numereIntregi)) {
        cout << "Multime vida\n";
    } else {
        cout << numereIntregi << '\n';
    }
    if (!strlen(numereRationale)) {
        cout << "Multime vida\n";
    } else {
        cout << numereRationale << '\n';
    }
    if (!strlen(numereIrationale)) {
        cout << "Multime vida\n";
    } else {
        cout << numereIrationale << '\n';
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}