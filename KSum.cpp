#include <fstream>
#include <deque>

using namespace std;

ifstream cin("ksum.in");
ofstream cout("ksum.out");

int const NMAX = 1e5 + 5;
int n, k, s[NMAX];
deque<int> q;

int main() {
    cin >> n >> k;
    int i, maxim;
    for (i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    maxim = s[k];
    q.push_back(0);
    for (i = k + 1; i <= n; i++) {
        while (!q.empty() && s[q.back()] >= s[i - k])
            q.pop_back();
        q.push_back(i - k);
        maxim = max(maxim, s[i] - s[q.front()]);
    }
    cout << maxim << '\n';
    cin.close();
    cout.close();
    return 0;
}