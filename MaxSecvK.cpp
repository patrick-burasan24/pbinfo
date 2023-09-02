#include <fstream>
#include <deque>

using namespace std;

ifstream cin("maxsecvk.in");
ofstream cout("maxsecvk.out");

int const NMAX = 1e5 + 5;
int n, k, a[NMAX];
deque<int> q;

int main() {
    int i;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    // Prelucram primele k elemente
    for (i = 1; i <= k; i++) {
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
    }
    // Afisam primul element maxim
    cout << a[q.front()] << ' ';
    // Continuam prelucrarea pentru restul elementelor
    for (i = k + 1; i <= n; i++) {
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
        // Daca elementul din stanga nu mai face parte dintr-un interval corect
        // (i.e. nu mai poate fi un maxim) il eliminam
        if (i - k == q.front())
            q.pop_front();
        // Afisam maximul
        cout << a[q.front()] << ' ';
    }
    cout << '\n';
    cin.close();
    cout.close();
    return 0;
}