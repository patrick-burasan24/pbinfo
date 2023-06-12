#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int n, m;
ll x_i, y_i;
vector<ll> d, rad;

void citire() {
    cin >> n;
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x_i >> y_i;
        d[i] = x_i * x_i + y_i * y_i;
    }
    cin >> m;
    rad.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> rad[i];
    }
}

int bin_search(ll r) {
    if (r * r < d[1]) { return 0; }
    if (r * r >= d[n]) { return n; }

    int lo, hi, mid;
    lo = 1;
    hi = n;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (r * r >= d[mid]) {
            lo = mid + 1; 
        } else {
            hi = mid - 1;
        }
    }
    return lo - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    citire();
    sort(d.begin(), d.end(), less<ll>());
    for (int i = 1; i <= m; ++i) {
        cout << bin_search(rad[i]) << ' ';
    }
    cout << '\n';
    return 0;
}