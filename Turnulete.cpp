

#include <iostream>
#include <fstream>
#include <map>
#define MOD 1e9 + 7
#define INF 1e9
typedef long long ll;
typedef long double ld;

using namespace std;

// ifstream in(".in");
// ofstream out(".out");

map<int, int> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        M[x]++;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        if (M.find(x) == M.end()) {
            cout << "0 ";
        } else {
            cout << 1LL * x * M[x] << ' ';
        }
    }
    cout << '\n';
    return 0;
}

