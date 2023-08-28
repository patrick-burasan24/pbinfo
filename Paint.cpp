#include <fstream>

using namespace std;

ifstream cin("paint.in");
ofstream cout("paint.out");

int const NMAX = 250005;
int n, m, k, d, l, cnt, a[NMAX], b[NMAX];

int main() {
    cin >> n >> k >> m;
    while (m--) {
        cin >> d >> l;
        b[d]++;
        b[d + l]--;
    }
    for (int i = 0; i < n; i++) {
        b[i] += b[i - 1];
        a[i] += b[i];
        if (a[i] < k)
            cnt++;
    }
    cout << cnt << '\n';
    cin.close();
    cout.close();
    return 0;
}