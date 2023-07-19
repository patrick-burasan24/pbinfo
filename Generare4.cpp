//------------------------------------------------
// Patrick Burasan
//------------------------------------------------
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <bitset>
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define precision(x) cout<<fixed<<setprecision(x);
#define _gcd(a, b) (b == 0? a : _gcd(b, a%b))
typedef long long int int64;
typedef unsigned long long int uint64;
typedef long double ld;
//------------------------------------------------
using namespace std;

void generare4(int n, int p2) {
    if (p2 <= n) {
        // idee: noi parcurgem un interval marcat de punctele
        // (st, dr], unde
        // st = puterea anterioara a lui 2
        // dr = putearea curenta a lui 2
        // formal: fie n puterea curenta a lui 2 => (2^(n-1), 2^n]
        for (int i = (1 << (p2 - 1)) + 1; i <= (1 << p2); ++i) {
            cout << i << " ";
            // Daca gasim mijlocul intervalului apelam functia ajutatoare
            // si continuam generarea sirului pe aceeasi idee
            if (i == ((1 << (p2 - 1)) + (1 << p2)) / 2)
                generare4(n, p2 + 1);
        }
    }
}

/* Nota: cazurile particulare 2^0 si 2^1 se afiseaza in afara functiei */
/* Dat fiind ca se poate realiza strategia de mai sus*/

void solve() {
    int n; cin >> n;
    cout << "1 ";
    generare4(n, 2);
    cout << "2\n";
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin.tie(0)->ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}
