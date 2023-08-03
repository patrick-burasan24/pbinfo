#include <iostream>
#include <cstring>
#define DIM 1000
typedef int Huge[DIM + 5];

using namespace std;

inline void attrib(Huge H, char *s) {
    H[0] = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
        H[++H[0]] = (int)(s[i] - '0');
}

inline void attrib_huge(Huge A, Huge B) {
    A[0] = B[0];
    for (int i = 1; i <= B[0]; i++)
        A[i] = B[i];
}

inline void divide(Huge H, const int &X) {
    unsigned long R = 0;
    for (int i = H[0]; i; i--) {
        R = R * 10 + H[i];
        H[i] = R / X;
        R %= X;
    }

    while (H[0] > 1 && !H[H[0]]) H[0]--;
}

inline void mult(Huge A, Huge B, Huge C) {
    unsigned long T = 0;
    C[0] = A[0] + B[0] - 1;
    for (int i = 1; i <= A[0] + B[0]; i++)
        C[i] = 0;
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

// Rezultatul cautat este 2^k, unde k = nr. de biti setati ai lui n
// Vom calcula rezultatul folsind exponentierea in timp logaritmic
inline void rise(Huge base, int exp, Huge r) {
    r[0] = 1;
    r[1] = 1;
    Huge aux;
    while (exp) {
        if (exp & 1) {
            // r = r * base;
            mult(r, base, aux);
            attrib_huge(r, aux);
        }
        // base = base * base;
        mult(base, base, aux);
        attrib_huge(base, aux);
        exp >>= 1;
    }
}

char s[DIM + 5];
Huge H, B, R;
int cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    attrib(H, s);
    while (H[0] != 1 || H[1] != 0) {
        cnt += (H[1] % 2);
        divide(H, 2);
    }

    B[0] = 1;
    B[1] = 2;
    rise(B, cnt, R);
    for (int i = R[0]; i; i--) cout << R[i];
    cout << '\n';
    return 0;
}