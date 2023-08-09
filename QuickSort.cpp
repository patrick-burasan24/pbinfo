#include <iostream>

using namespace std;

inline void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

inline int partition(int *A, int st, int dr) {
    int lo = st - 1, hi = dr - 1;
    for (int i = st; i <= hi; i++) {
        if (A[i] <= A[dr]) {
            lo++;
            Swap(&A[lo], &A[i]);
        }
    }
    Swap(&A[lo + 1], &A[dr]);
    return lo + 1;
}

inline void quickSort(int *A, int st, int dr) {
    if (st < dr) {
        int pivot = partition(A, st, dr);
        quickSort(A, pivot + 1, dr);
        quickSort(A, st, pivot - 1);
    }
}

int n, v[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    quickSort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}