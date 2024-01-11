#include <bits/stdc++.h>

using namespace std;

ifstream fin("paritatesiruri.in");
ofstream fout("paritatesiruri.out");

constexpr int NMAX = 10005;

int k;
int n;
char s[NMAX];

void outputEvenString(char *s) {
    for (size_t i = 0; i < n; i += 2)
        fout << s[i];
}

void outputOddString(char *s) {
    for (size_t i = 1; i < n; i += 2) 
        fout << s[i];
}

void solve() {
    fin.getline(s, NMAX);
    n = strlen(s);
    outputOddString(s);
    fout << ' ';
    outputEvenString(s);
    fout << '\n';
}

int main() {
    fin >> k;
    fin.ignore();
    while (k--)
        solve();
    fin.close();
    fout.close();
    return 0;
}