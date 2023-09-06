#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("gustare.in");
ofstream cout("gustare.out");

const int NMAX = 500005;
int n, m, t, val, a[NMAX], b[NMAX];
bool good;

int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    cin >> t;
    while (t--) {
        cin >> val;
        i = 1;
        j = m;
        good = false;
        while (i <= n && j >= 1) {
            if (a[i] + b[j] == val) {
                good = true;
                break;
            }
            else if (a[i] + b[j] > val)
                j--;
            else
                i++;
        }
        if (good)
            cout << "DA\n";
        else
            cout << "NU\n";
    }
    cin.close();
    cout.close();
    return 0;
}