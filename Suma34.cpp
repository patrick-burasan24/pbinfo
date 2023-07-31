#include <iostream>
#define MAX 50000
typedef int Huge[MAX+5];

using namespace std;

inline void AttribHuge(Huge A, Huge B) {
    for (int i = 1; i <= B[0]; i++)
        A[i] = B[i];
    A[0] = B[0];
}

inline void MultHuge(Huge A, Huge B, Huge C) {
    unsigned T = 0;
    C[0] = A[0] + B[0] - 1;
    for (int i = 1; i <= A[0] + B[0]; i++) C[i] = 0;
    for (int i = 1; i <= A[0]; i++)
        for (int j = 1; j <= B[0]; j++)
            C[i + j - 1] += A[i] * B[j];
    // Sumele intermediare
    for (int i = 1; i <= C[0]; i++) {
        C[i] += T;
        T = C[i] / 10;
        C[i] %= 10;
    }

    while (T) {
        C[++C[0]] = T % 10; T /= 10;
    }
}

// Vom face operatia 2^n folosind exponentierea in timp logaritmic
inline void rise(Huge baza, int exp, Huge rez) {
    Huge aux;
    rez[0] = 1; rez[1] = 1;
    while (exp) {
        if (exp & 1) {
            // rez = rez * baza;
            MultHuge(rez, baza, aux);
            AttribHuge(rez, aux);
        }
        MultHuge(baza, baza, aux);
        AttribHuge(baza, aux);
        exp >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    Huge baza, rez;
    baza[0] = 1;
    baza[1] = 2;
    rise(baza, n, rez);

    unsigned long cnt = 0;
    for (int i = 1; i <= rez[0]; i++)
        cnt += rez[i];
    cout << cnt << '\n';
    return 0;
}
