// Solutia foloseste o varianta optimizata a Sortarii prin Interclasare
#include <iostream>

using namespace std;

int const NX = 1e5;

int n, v[NX + 5], u[NX + 5];

inline void mergeSort(int const &l, int const &r) {
    int m = (l + r) >> 1, i, j, k;

    if (l == r) return;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    for (i = l, j = m + 1, k = l; i <= m || j <= r; )
        if (j > r || (i <= m && v[i] < v[j]))
            u[k++] = v[i++];
        else
            u[k++] = v[j++];
    for (i = l; i <= r; i++)
        v[i] = u[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}