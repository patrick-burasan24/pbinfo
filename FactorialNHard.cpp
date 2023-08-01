#include <iostream>
#define MAX 30000
typedef int Huge[MAX+5];

using namespace std;

int n;
Huge N, R;

inline void AttribHuge(Huge A, Huge B) {
    for (int i = 1; i <= B[0]; i++)
        A[i] = B[i];
    A[0] = B[0];
}

inline void Mult(Huge A, const int &scalar) {
    unsigned T = 0;
    for (int i = 1; i <= A[0]; i++) {
        A[i] = A[i] * scalar + T;
        T = A[i] / 10;
        A[i] %= 10;
    }

    while (T) A[++A[0]] = T % 10, T /= 10;
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

    while (T) C[++C[0]] = T % 10, T /= 10;
}

// Pentru a calcula (n!)^n vom folosi exponentierea in timp logaritmic
inline void rise(Huge base, int exp, Huge r) {
    r[0] = 1; r[1] = 1;
    Huge aux;
    while (exp) {
        if (exp & 1) {
            // r = r * base;
            MultHuge(r, base, aux);
            AttribHuge(r, aux);
        }
        // base = base * base
        MultHuge(base, base, aux);
        AttribHuge(base, aux);
        exp >>= 1;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    N[0] = 1; N[1] = 1;
    // factorial
    for (int i = 1; i <= n; i++)
        Mult(N, i);
    rise(N, n, R);
    for (int i = R[0]; i; i--) cout << R[i];
    cout << '\n';
    return 0;
}