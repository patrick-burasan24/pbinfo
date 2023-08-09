#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

inline int partition(int *A, int st, int dr, int semn) {
    int lo = st - 1;
    int hi = dr - 1;
    for (int i = st; i <= hi; i++)
        if (semn * A[i] <= semn * A[dr]) {
            lo++;
            swap(&A[lo], &A[i]);
        }
    swap(&A[lo + 1], &A[dr]);
    return (lo + 1);
}

inline void quickSort(int *A, int st, int dr, int semn) {
    if (st < dr) {
        int piv = partition(A, st, dr, semn);
        quickSort(A, st, piv - 1, semn);
        quickSort(A, piv + 1, dr, semn);
    }
}

int n, k, v[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    quickSort(v, 0, k - 1, 1);
    quickSort(v, k, n - 1, -1);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}