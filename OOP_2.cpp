#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("oop_2.in");
ofstream fout("oop_2.out");

class Tablou {
    public:
        int *t;
        int n;

        Tablou(int dim, int a, int b, int c, int d) {
            n = dim;
            t = new int[n];
            t[0] = a;
            for (int i = 1; i < n; i++)
                t[i] = 1 + (t[i - 1] * b + c) % d;
        }

        ~Tablou() {
            n = 0;
            delete[] t;
        }

        int Max() {
            int maxi = t[0];
            for (int i = 1; i < n; i++)
                maxi = max(maxi, t[i]);
            return maxi;
        }

        int Cauta(int val) {
            int p = -1;
            for (int i = 0; i < n; i++)
                if (t[i] == val) {
                    p = i;
                    break;
                }
            return p;
        }
};

int main() {
    Tablou ob(10, 2, 7, 7, 9);
    for (int i = 0; i < 10; i++)
        fout << ob.t[i] << ' ';
    fout << '\n';
    fout << ob.Max() << '\n';
    fout << ob.Cauta(5) << '\n';
    return 0;
}
