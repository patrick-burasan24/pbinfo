#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("ifelse.in");
ofstream cout("ifelse.out");

const int NMAX = 500005;
const char sep[] = " ";
char a[NMAX];
int n;

struct Cuv {
    char sir[10];
};

int Rezolvare(char *a) {
    int top = 0;
    int op = 0;
    Cuv st[NMAX];
    char *p = strtok(a, sep);
    while (p != NULL) {
        if (strcmp(p, "if") == 0) {
            strcpy(st[++top].sir, p);
        }
        else if (strcmp(p, "else") == 0) {
            if (top == 0) {
                op++;
                strcpy(st[++top].sir, "if");
            }
            else {
                top--;
            }
        }
        p = strtok(NULL, sep);
    }
    if (top % 2 == 1)
        return -1;
    return op + (top / 2);
}

int main() {
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        cin.getline(a, NMAX);
        cout << Rezolvare(a) << '\n';
    }
    return 0;
}