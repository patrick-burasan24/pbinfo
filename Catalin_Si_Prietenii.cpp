#include <fstream>
#include <cstring>
#include <vector>

/**
 * Class that speeds up I/O streams
 */

class InParser {
    private:
        std::vector<char> str;
        int ptr;
        std::ifstream fin;
    
    private:
        char get_char() {
            if (ptr == (int)str.size()) {
                fin.read(str.data(), (int)str.size());
                ptr = 0;
            }

            return str[ptr++];
        }

        template<class T>
        T get_int() {
            char chr;
            do {
                chr = get_char();
            } while (!isdigit(chr) && (chr != '-'));

            int sgn = +1;
            if (chr == '-') {
                sgn = -1;
                chr = get_char();
            }

            T num = 0;
            while (isdigit(chr)) {
                num = num * 10 + (chr - '0');
                chr = get_char();
            }

            return sgn * num;
        }

    public:
        InParser(const char *name) : str((int)1e5), ptr((int)str.size()), fin(name) { }
        ~InParser() { fin.close(); }

        template<class T>
        friend InParser &operator >> (InParser &in, T &num) {
            num = in.get_int<T>();
            return in;
        }
};

class OutParser { 
    private:
        std::vector<char> str;
        int ptr;
        std::ofstream fout;
    
    private:
        void put_char(char chr) {
            if (ptr == (int)str.size()) {
                fout.write(str.data(), (int)str.size());
                ptr = 0;
            }

            str[ptr++] = chr;
        }

        template<class T>
        void put_int(T num) {
            if (num < 0) {
                put_char('-');
                num *= -1;
            }

            if (num > 9)
                put_int(num / 10);
            put_char(num % 10 + '0');
        }

    public:
        OutParser(const char *name) : str((int)1e5), ptr(0), fout(name) { }
        ~OutParser() { fout.write(str.data(), ptr); fout.close(); }

        template<class T>
        friend OutParser &operator << (OutParser &out, const T num) {
            out.put_int(num);
            return out;
        }

        friend OutParser &operator << (OutParser &out, const char chr) {
            out.put_char(chr);
            return out;
        }

        friend OutParser &operator << (OutParser &out, const char *str) {
            for (int i = 0; str[i]; i++)
                out.put_char(str[i]);
            return out;
        }
};

/**
 * Class that simulates the Disjoint Set Union algorithm
*/

class DisjointSetUnion {
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int n;
    
    public:
        DisjointSetUnion(const int _n) {
            this->n = _n;
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 1; i <= n; i++)
                parent[i] = i;
        }

        int find(const int u) {
            if (u == parent[u])
                return u;
            return parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v)
                return;
            
            if (size[v] > size[u]) 
                std::swap(u, v);
            
            parent[v] = u;
            size[u] += size[v];
        }
        
        int get_size(const int u) {
            return size[find(u)];
        }
};

int n, k;

int main() {
    InParser cin("prieteni.in");
    OutParser cout("prieteni.out");

    cin >> n >> k;
    DisjointSetUnion dsu(n);
    while (k--) {
        int cod, x, y, p;
        cin >> cod;
        if (cod == 1) {
            cin >> x >> y;
            dsu.unite(x, y);
        }
        else {
            cin >> p;
            cout << dsu.get_size(p) << '\n';
        }
    }
    return 0;
}