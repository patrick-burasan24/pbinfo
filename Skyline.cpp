#include <fstream>

using namespace std;

ifstream cin("skyline.in");
ofstream cout("skyline.out");

const int NMAX = 40005;
int n, top, st[NMAX], h[NMAX], s[NMAX], stg[NMAX], drp[NMAX];
long long maxi;

void Citire() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        cin >> s[i];
        s[i] += s[i - 1];
    }
}

void Rezolvare() {
    maxi = -1;
    h[0] = h[n + 1] = -1;
    top = 0;
    st[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (h[st[top]] >= h[i])
            top--;
        stg[i] = i - st[top];
        st[++top] = i;
    }
    top = 0;
    st[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (h[st[top]] >= h[i])
            top--;
        drp[i] = st[top] - i;
        st[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        maxi = max(maxi, 1LL * h[i] * (s[i + drp[i] - 1] - s[i - stg[i]]));
}

void Afisare() {
    cout << maxi << '\n';
}

int main() {
    Citire();
    Rezolvare();
    Afisare();
    cin.close();
    cout.close();
    return 0;
}