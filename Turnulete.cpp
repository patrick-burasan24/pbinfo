#include <iostream>
#include <fstream>
#include <vector>
#define MOD 1e9 + 7
#define INF 1e9
typedef long long ll;
typedef long double ld;

using namespace std;

// ifstream in(".in");
// ofstream out(".out");
int n, m, p, q;
vector<ll> a, b;

void load() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
}

int bin_search1(ll x) {

    ll lo, hi, mid;
    int p = 0;
    lo = 0;
    hi = n - 1;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (x == a[mid]) {
            p = mid;
            lo = mid + 1;
        } else if (x > a[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return p;
}

int bin_search2(ll x) {
    ll lo, hi, mid;
    int q = 1;
    lo = 0;
    hi = n - 1;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (x == a[mid]) {
            q = mid;
            hi = mid - 1;
        } else if (x > a[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    load();
    for (int i = 0; i < m; ++i) {
        p = bin_search1(b[i]);
        q = bin_search2(b[i]);
        cout << 1LL * b[i] * (p - q + 1) << ' ';
    }
    cout << '\n';       
    return 0;
}

