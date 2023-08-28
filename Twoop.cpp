#include <fstream>

using namespace std;

ifstream cin("twoop.in");
ofstream cout("twoop.out");

int const NMAX = 100005;
int N, t1, t2, st, dr, x, p;
long long a[NMAX], b[NMAX];

int main() {
    cin >> N >> t1 >> t2;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    while (t1--) {
        cin >> st >> dr >> x;
        b[st] += x;
        b[dr + 1] -= x;
    }
    for (int i = 1; i <= N; i++) {
        b[i] += b[i - 1];
        a[i] += b[i];
    }
    while (t2--) {
        cin >> p;
        cout << a[p] << '\n';
    }
    cin.close();
    cout.close();
    return 0;
}