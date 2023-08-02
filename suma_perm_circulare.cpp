#include <iostream>
#include <fstream>
#include <cstring>
#define DIM 200000
typedef long Huge[DIM + 5];
typedef unsigned long long ull;

using namespace std;

// ifstream cin("test.in");
// ofstream cout("test.out");

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char s[DIM + 5], ans[500005];
    ull sum = 0;
    cin.get(s, DIM + 5);
    for (int i = 0; i < strlen(s); i++)
        sum += (int)(s[i] - '0');
    
    ull T = 0;
    for (int i = 0; i < strlen(s); i++) {
        ans[i] = ((sum + T) % 10) + '0';
        T = (sum + T) / 10;
    }

    int L = strlen(s) - 1;
    while (T) {
        ans[++L] = (T % 10 + '0');
        T /= 10;
    }

    for (int i = L; i >= 0; i--)
        cout << ans[i];

    return 0;
}