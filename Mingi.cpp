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

int n, k, x;
vector<int> a;
vector<ll> sp;

void load() {
    cin >> n;
    sp.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        sp[i] = sp[i - 1] + x;
    }
    cin >> k;
    a.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
}

int bin_search(int x) {
    int lo, hi, mid;
    lo = 1;
    hi = n;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (x <= sp[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return hi + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
  
    load();
    for (int i = 0; i < k; ++i) {
        cout << bin_search(a[i]) << ' ';
    }
    cout << '\n';   
    return 0;
}

