#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>

/**
 * Struct that stores info about the edges
 */

struct Edge {
    int parent;
    int child;
    int cost;

    friend bool operator < (const Edge &A, const Edge &B) {
        return A.cost < B.cost;
    }
};

using vi = std::vector<int>;
using vc = std::vector<char>;
using ve = std::vector<Edge>;

/**
 * Classes that speed up the I/O process
 */

class InParser {
    private:
        vc str;
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
        vc str;
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
 * Class that simulates the Disjoint Set Union for Kruskal's algo 
 */

class DisjointSetUnion {
    private:
        vi parent;
        vi size;
        int n;
    
    public:
        DisjointSetUnion(const int _n) {
            this->n = _n;
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 1; i <= n; i++)
                parent[i] = i;
        }
        ~DisjointSetUnion() { }

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
};

/**
 * Class that created the MST from scratch
 */

class MinimumSpanningTree {
    private:
        int n;
    
    public:
        MinimumSpanningTree(const int _n) {
            this->n = _n;
        }
        ~MinimumSpanningTree() { }

        int kruskal(ve &list) {
            std::sort(list.begin(), list.end());
            DisjointSetUnion dsu(n);

            int res = 0;
            for (auto w : list) {
                int u = w.parent;
                int v = w.child;
                int c = w.cost;

                if (dsu.find(u) != dsu.find(v)) {
                    dsu.unite(u, v);
                    res += c;
                }
            }

            return res;
        }
};

int n, m, cod, u, v, c;
ve list;

int main() {
    InParser cin("plimbare1.in");
    OutParser cout("plimbare1.out");

    cin >> n >> m;
    while (m--) {
        cin >> cod >> u >> v;
        c = 0;
        if (cod == 2)
            cin >> c;
        list.push_back( { u, v, c } );
    }

    MinimumSpanningTree mst(n);
    cout << mst.kruskal(list) << '\n';
    return 0;
}