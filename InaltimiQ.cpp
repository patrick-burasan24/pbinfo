#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int n;
struct copil {
    int idx;
    int h;
} v[1005];

inline void swap(copil *a, copil *b) {
    copil tmp = *a;
    *a = *b;
    *b = tmp;
}

inline int partition(copil *A, int st, int dr) {
    int lo = st - 1, hi = dr - 1;
    for (int i = st; i <= hi; i++) 
        if (A[i].h <= A[dr].h) {
            lo++;
            swap(&A[lo], &A[i]);
        }
    swap(&A[lo + 1], &A[dr]);
    return lo + 1;
}

inline int randomPartition(copil *A, int st, int dr) {
    srand(time(NULL));
    int random = st + rand() % (dr - st);
    swap(&A[random], &A[dr]);
    return partition(A, st, dr);
}

inline void quickSort(copil *A, int st, int dr) {
    if (st < dr) {
        int pivot = randomPartition(A, st, dr);
        quickSort(A, st, pivot - 1);
        quickSort(A, pivot + 1, dr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].h;
        v[i].idx = i;
    }
    quickSort(v, 0, n - 1);
    for (int i = 0; i < n; i++) 
        cout << v[i].idx + 1 << ' ';
    cout << '\n';
    return 0;
}