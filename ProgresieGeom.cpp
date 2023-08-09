#include <iostream>
#include <cstring>
#define MAX 100000
typedef int Huge[MAX+5];

using namespace std;

inline void AttribValue(Huge A, char *s) {
    A[0] = 0;
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--)
        A[++A[0]] = (int)(s[i] - '0');
}

inline void AttribHuge(Huge A, Huge B) {
    for (int i = 1; i <= B[0]; i++)
        A[i] = B[i];
    A[0] = B[0];
}

inline void Shl(Huge A, const int &scalar) {
    memmove(&A[scalar + 1], &A[1], sizeof(int)*A[0]);
    memset(&A[1], 0, scalar);
    A[0] += scalar;
}

inline int Sgn(Huge A, Huge B) {
    // Eliminam zerourile nesemnificative, daca este nevoie
    while (A[0] && !A[A[0]]) A[0]--;
    while (B[0] && !B[B[0]]) B[0]--;

    if (A[0] < B[0])
        return -1;
    else if (B[0] < A[0])
        return +1;
    
    for (int i = A[0]; i; i--)
        if (A[i] < B[i])
            return -1;
        else if (B[i] < A[i])
            return +1;
    return 0;
}

inline void Subtract(Huge A, Huge B) {
    unsigned T = 0;
    for (int i = B[0] + 1; i <= A[0]; i++) B[i] = 0;
    for (int i = 1; i <= A[0]; i++) {
        A[i] -= (B[i] + T);
        if (A[i] < 0) T = 1; else T = 0;
        if (T) A[i] += 10;
    }

    while (A[0] > 1 && !A[A[0]]) A[0]--; 
}

inline void DivideHuge(Huge A, Huge B, Huge C, Huge R) {
    R[0] = 0; C[0] = A[0];
    for (int i = A[0]; i; i--) {
        Shl(R, 1); R[1] = A[i];
        C[i] = 0;
        while (Sgn(B, R) != 1) {
            C[i]++;
            Subtract(R, B);
        }
    }

    while (C[0] > 1 && !C[C[0]]) C[0]--;
}

inline void MultHuge(Huge A, Huge B, Huge C) {
    unsigned T = 0;
    C[0] = A[0] + B[0] - 1;
    for (int i = 1; i <= A[0] + B[0];)
        C[i++] = 0;
    for (int i = 1; i <= A[0]; i++)
        for (int j = 1; j <= B[0]; j++)
            C[i + j -1] += A[i] * B[j];
    // Sumele intermediare
    for (int i = 1; i <= C[0]; i++) {
        C[i] += T; 
        T = C[i] / 10; 
        C[i] %= 10;
    }

    while (T) C[++C[0]] = T % 10, T /= 10;
}

// Pentru q^(n-1) vom folosi exponentierea in timp logaritmic
inline void rise(Huge base, int exp, Huge r) {
    r[0] = 1;
    r[1] = 1;
    Huge aux;
    while (exp) {
        if (exp & 1) {
            // r = r * base;
            MultHuge(r, base, aux);
            AttribHuge(r, aux);
        }
        // base = base * base;
        MultHuge(base, base, aux);
        AttribHuge(base, aux);
        exp >>= 1;
    }
}

char x[MAX+5], a[MAX+5], b[MAX+5];
Huge X, A, B, C, R;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> a >> b;
    cin >> n;
    AttribValue(X, x);
    AttribValue(A, a);
    AttribValue(B, b);
    DivideHuge(A, B, C, R);
    rise(C, n - 1, R);
    MultHuge(X, R, C);
    for (int i = C[0]; i; i--) cout << C[i];
    cout << '\n';
    return 0;   
}
