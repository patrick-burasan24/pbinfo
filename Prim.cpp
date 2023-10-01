    #include <fstream>
    #include <vector>
    #include <queue>
    #include <cstring>

    struct edge {
        int parent;
        int child;
        int cost;

        bool operator < (const edge &a) const {
            return a.cost < cost;
        }
    };

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

    int n, m, u, v, c;
    std::vector<int> parent;
    std::vector<std::vector<edge>> adj;

    class MinimumSpanningTree {
        private:
            std::priority_queue<edge> q;
            std::vector<bool> used;
            int n;
        
        public:
            MinimumSpanningTree(const int _n) : n(_n) { }
            ~MinimumSpanningTree() { }

            int prim(int startingNode) {
                used.resize(n + 1, false);
                q.push( { 0, startingNode, 0});

                int res = 0;
                while (!q.empty()) {
                    edge w = q.top();
                    q.pop();

                    if (used[w.child]) 
                        continue;

                    used[w.child] = true;
                    res += w.cost;
                    parent[w.child] = w.parent;

                    for (auto u : adj[w.child])
                        if (!used[u.child])
                            q.push( { u.parent, u.child, u.cost } );
                }

                return res;
            }
    };

    int main() {
        InParser cin("prim.in");
        OutParser cout("prim.out");

        cin >> n >> m;
        parent.resize(n + 1);
        adj.resize(n + 1);

        while (m--) {
            cin >> u >> v >> c;
            adj[u].push_back( { u, v, c } );
            adj[v].push_back( { v, u, c } );
        }

        MinimumSpanningTree mst(n);
        cout << mst.prim(1) << '\n';
        for (int i = 1; i <= n; i++)
            cout << parent[i] << ' ';
        cout << '\n';
        return 0;
    }