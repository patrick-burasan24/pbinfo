#include <fstream>

using namespace std;

ifstream cin("easyquery.in");
ofstream cout("easyquery.out");

int const NMAX = 100005;
int N, T, tip, st, dr, x;
long long a[NMAX], b[NMAX];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    cin >> T;
    while (T--) {
        cin >> tip >> st >> dr >> x;
        if (tip == 1) {
            b[st] += x;
            b[dr + 1] -= x;
        } else {
            b[st] -= x;
            b[dr + 1] += x;
        }
    }
    for (int i = 1; i <= N; i++) {
        b[i] += b[i - 1];
        a[i] += b[i];
        cout << a[i] << ' ';
    }
    cout << '\n';
    cin.close();
    cout.close();
    return 0;
}