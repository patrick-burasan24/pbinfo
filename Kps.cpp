#include <bits/stdc++.h>

using namespace std;

ifstream fin("kps.in");
ofstream fout("kps.out");

constexpr int NMAX = 1e4 + 5;

int c;
string s;
vector<pair<int, multiset<string>>> vect(NMAX);

int kps(const string s) {
    int k = 0;
    int kmax = 0;

    string pref;
    string suff;

    for (size_t i = 0, j = s.size() - 1; i < s.size() - 1; i++, j--) {
        k++;
        suff += s[j];
        pref += s[i];
        reverse(suff.begin(), suff.end());
        // fout << pref << '\n' << suff << '\n';
        if (suff == pref) {
            kmax = k;
        }
        reverse(suff.begin(), suff.end());
    }
    return kmax;
}

void task_1() {
    fin >> s;
    fout << kps(s) << '\n';
}

void task_2() {
    int kmax = 0;
    while (fin >> s) {
        int k = kps(s);
        kmax = max(kmax, k);
        vect[k].first++;
        vect[k].second.insert(s);
    }
    for (size_t i = 0; i <= kmax; i++) {
        fout << vect[i].first << ' ';
        for (auto it : vect[i].second) {
            fout << it << ' ';
        }
        fout << '\n';
    }
}

int main() {
    fin >> c;
    switch (c) {
        case 1: task_1(); break;
        case 2: task_2(); break;
    }
    fin.close();
    fout.close();
    return 0;
}