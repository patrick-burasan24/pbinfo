#include <fstream>

using namespace std;

ifstream cin("secvb.in");
ofstream cout("secvb.out");

const int NMAX = 50005;
int n, t, k, ans, x, a[NMAX];

int Biti(int x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        cnt++;
    }
    return cnt;
}

int main() {
    cin >> n >> t;
    int i, j;
    for (i = 1; i <= n; i++) {
        cin >> x;
        a[i] = Biti(x);
    }
    j = 1;
    for (i = 1; i <= n; i++) {
        k += a[i];
        while (k > t) 
            k -= a[j++];
        if (k == t)
            ans++;
    }
    cout << ans << '\n';
    cin.close();
    cout.close();
    return 0;
}