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

    set<int> s;

    void generare2(int n, int a, int x, int y) {
        if (a + x <= n) {
            if (s.count(a + x) == 0) {
                s.insert(a + x);
                generare2(n, a + x, x, y);
            }
        }

        if (a + y <= n) {
            if (s.count(a + y) == 0) {
                s.insert(a + y);
                generare2(n, a + y, x, y);
            }
        }
    }

    void solve() {
        int n, a, x, y;
        cin >> n >> a >> x >> y;
        s.insert(a);
        generare2(n, a, x, y);
        for (auto it: s)
            cout << it << " ";
        cout << "\n";
    }

    int main() {
        // freopen("test.in", "r", stdin);
        // freopen("test.out", "w", stdout);
        cin.tie(0)->ios_base::sync_with_stdio(0);
        
        solve();
        return 0;
    }