#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    int val;
    int dgt;
    int sum;
    int prod;
} Elem;

const int NMAX = 1e6 + 5;
int n;
Elem a[NMAX];
int fr[10];

class InParser {
    private:
        vector<char> str;
        int ptr;
        ifstream fin;
    
    private:
        char getChar() {
            if (ptr == (int)str.size()) {
                fin.read(str.data(), (int)str.size());
                ptr = 0;
            }
            return str[ptr++];
        }

        template<class T>
        T getInt() {
            char chr;
            do {
                chr = getChar();
            } while (!isdigit(chr) && (chr != '-'));

            int sgn = +1;
            if (chr == '-') {
                sgn = -1;
                chr = getChar();
            }

            T num = 0;
            while (isdigit(chr)) {
                num = num * 10 + (chr - '0');
                chr = getChar();
            }

            return sgn * num;
        }
    
    public:
        InParser(const char *name) : str((int)1e5), ptr((int)str.size()), fin(name) { }
        ~InParser() { fin.close(); }

        template<class T>
        friend InParser& operator>>(InParser &in, T &num) {
            num = in.getInt<T>();
            return in;
        }
};

class OutParser {
    private:
        vector<char> str;
        int ptr;
        ofstream fout;
    
    private:
        void putChar(char chr) {
            if (ptr == (int)str.size()) {
                fout.write(str.data(), (int)str.size());
                ptr = 0;
            }
            str[ptr++] = chr;
        }

        template<class T>
        void putInt(T num) {
            if (num < 0) {
                putChar('-');
                num *= -1;
            }

            if (num > 9)
                putInt(num / 10);
            putChar(num % 10 + '0');
        }
    
    public:
        OutParser(const char *name) : str((int)1e5), ptr(0), fout(name) { }
        ~OutParser() { fout.write(str.data(), ptr); fout.close(); }

        template<class T>
        friend OutParser& operator<<(OutParser &out, const T num) {
            out.putInt(num);
            return out;
        }

        friend OutParser& operator<<(OutParser &out, const char chr) {
            out.putChar(chr);
            return out;
        }

        friend OutParser& operator<<(OutParser &out, const char *str) {
            for (int i = 0; str[i]; i++)
                out.putChar(str[i]);
            return out;
        }
};

inline bool cmp(const Elem &A, const Elem &B) {
    if (A.dgt == B.dgt) {
        if (A.sum == B.sum) {
            if (A.prod == B.prod)
                return A.val < B.val;
            return A.prod < B.prod;
        }
        return A.sum < B.sum;
    }
    return A.dgt > B.dgt;
}

int main() {
    InParser fin("sort4.in");
    OutParser fout("sort4.out");
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> a[i].val;
        int cnt, s, p, tmp;
        cnt = s = 0;
        p = 1;
        tmp = a[i].val;
        do {
            s += (tmp % 10);
            p *= (tmp % 10);
            if (fr[tmp % 10] != i) {
                cnt++;
                fr[tmp % 10] = i;
            }
            tmp /= 10;
        } while (tmp);

        a[i].dgt = cnt;
        a[i].sum = s;
        a[i].prod = p;
    }
    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        fout << a[i].val << ' ';
    fout << '\n';
    return 0;
}