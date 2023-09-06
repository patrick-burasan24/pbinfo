#include <fstream>

using namespace std;

ifstream cin("secvmaxval.in");
ofstream cout("secvmaxval.out");

const int NMAX = 200005;
int n, maxi, a[NMAX];
long long val, s;

int main() {
    int i, j;
    cin >> n >> val;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    j = 1;
    for (i = 1; i <= n; i++) {
        s += a[i];
        while (s > val) 
            s -= a[j++];
        maxi = max(maxi, i - j + 1);
    }
    cout << maxi << '\n';
    cin.close();
    cout.close();
    return 0;
}