#include <fstream>
#include <cstdlib>
#include <time.h>
#define int unsigned

using namespace std;

ifstream fin("statisticiordine.in");
ofstream fout("statisticiordine.out");

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

inline int partition(int *A, int st, int dr) {
    int lo = st - 1, hi = dr - 1;
    for (int i = st; i <= hi; i++)
        if (A[i] <= A[dr]) {
            lo++;
            swap(&A[i], &A[lo]);
        }
    swap(&A[lo + 1], &A[dr]);
    return lo + 1;
}

inline int randomPartition(int *A, int st, int dr) {
    srand(time(NULL));
    int random = st + rand() % (dr - st + 1);
    swap(&A[random], &A[dr]);
    return partition(A, st, dr);
}

inline int quickSelect(int *A, int st, int dr, int k) {
    int pivot = randomPartition(A, st, dr);
    if (pivot == k)
        return A[pivot];
    
    if (pivot < k)
        return quickSelect(A, pivot + 1, dr, k);
    
    return quickSelect(A, st, pivot - 1, k);
}

int n, k, v[4000005];

signed main() {
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    fout << quickSelect(v, 1, n, k);
    fin.close();
    fout.close();
    return 0;
}