#include <iostream>

using namespace std;

int n, v[100005], u[100005];

inline void merge(int *A, int *B, int const &st, int const &mid, int const &dr) {
    int i = st, j = mid + 1, k = st - 1;

    while (i <= mid && j <= dr) {
        if (A[i] < A[j]) {
            B[++k] = A[i++];
        } else {
            B[++k] = A[j++];
        }
    }

    for (; i <= mid; i++) B[++k] = A[i];
    for (; j <= dr; j++) B[++k] = A[j];
    for (i = st; i <= dr; i++) A[i] = B[i];
}

inline void mergeSort(int *A, int *B, int const &st, int const &dr) {
    if (st < dr) {
        int mid = (st + dr) >> 1;
        mergeSort(A, B, st, mid);
        mergeSort(A, B, mid + 1, dr);
        merge(A, B, st, mid, dr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    mergeSort(v, u, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}