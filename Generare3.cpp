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
typedef long long int int64;
typedef unsigned long long int uint64;
typedef long double ld;
//------------------------------------------------
using namespace std;

set<string> s;

void generare3(int n, string sir) {
    if (sz(sir) < n) {
        generare3(n, sir + "0");
        generare3(n, sir + "1");
    } else if (sz(sir) == n) {
        s.insert(sir);
    }
}

void solve() {
    int n; cin >> n;
    string sir;
    generare3(n, sir);
    for (auto it: s)
        cout << it << "\n";
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin.tie(0)->ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}