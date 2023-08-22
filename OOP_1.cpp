#include <fstream>

using namespace std;

ifstream fin("oop_1.in");
ofstream fout("oop_1.out");

class A
{
public:
    int a, b;
    // constructor
    A(int _a, int _b)
    {
        a = _a; b = _b;
    }
    // functie membra: returneaza suma dintre a si b
    int Suma() 
    {
        return a + b;
    }
};


int main() {
    int x, y;
    fin >> x >> y;
    A ob(x, y);
    fout << ob.Suma();
    fin.close();
    fout.close();
}