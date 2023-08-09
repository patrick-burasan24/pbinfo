#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

ifstream fin("halfsortqs.in");
ofstream fout("halfsortqs.out");

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

inline int partition(int *A, int *X, int st, int dr, int semn) {
    int lo = st - 1;
    int hi = dr - 1;
    for (int i = st; i <= hi; i++)
        if (semn * A[X[i]] <= semn * A[X[dr]]) {
            lo++;
            swap(&A[X[i]], &A[X[lo]]);
        }
    swap(&A[X[lo + 1]], &A[X[dr]]);
    return lo + 1;
}

inline int randomPartition(int *A, int *X, int st, int dr, int semn) {
    srand(time(NULL));
    int random = st + rand() % (dr - st);
    swap(&A[X[random]], &A[X[dr]]);
    return partition(A, X, st, dr, semn);
}

inline void quickSort(int *A, int *X, int st, int dr, int semn) {
    if (st < dr) {
        int piv = randomPartition(A, X, st, dr, semn);
        quickSort(A, X, st, piv - 1, semn);
        quickSort(A, X, piv + 1, dr, semn);
    }
}

int n, cnt_pos, cnt_neg, X[100005], Y[100005], A[100005];

int main() {
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> A[i];
        if (A[i] >= 0) X[cnt_pos++] = i;
        else Y[cnt_neg++] = i;
    }
    quickSort(A, X, 0, cnt_pos - 1, -1);
    quickSort(A, Y, 0, cnt_neg - 1, 1);
    for (int i = 0; i < n; i++)
        fout << A[i] << ' ';
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}