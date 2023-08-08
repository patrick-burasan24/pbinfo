#include <fstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

ifstream fin("serbare1.in");
ofstream fout("serbare1.out");

int32_t i, j, ultimul, N, X;
string prop, nume;
map<int32_t, set<string > > M;

int main() {
    fin >> N;
    // Facem aceasta citire, deoarece vrem sa golim buffer-ul
    getline(fin, prop);
    for (i = 1; i <= N; i++) {
        getline(fin, prop);
        X = 0;
        nume = "";
        // Dupa ce realizam citirea randului curent, adaugam caracterele
        // relevante in campurile lor specifice (ex. litera la nume si cifra la X)
        for (j = 0; j < (int)prop.size(); j++)
            if (prop[j] < '0' || prop[j] > '9')
                nume += prop[j];
            else
                X = X * 10 + (prop[j] - '0');
        M[X].insert(nume);
    }
    fout << M.size();
    ultimul = -1;
    // Dupa ce s-au adaugat numele in set-urile avand drept cheie inaltimea
    // folosim un iterator ce ia map-ul de la capat si afisam ceea ce ni se cere
    for (auto h = M.rbegin(); h != M.rend(); h++) {
        if (h->first != ultimul) {
            ultimul = h->first;
            fout << '\n' << h->second.size() << ' ';
        }
        for (auto pers : h->second) 
            fout << pers;
    }
    fin.close();
    fout.close();
    return 0;
}