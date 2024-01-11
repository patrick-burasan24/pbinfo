#include <bits/stdc++.h>

std::ifstream fin("s_p_c_2.in");
std::ofstream fout("s_p_c_2.out");

std::vector<std::string> subiecte;
std::vector<std::string> predicate;
std::vector<std::string> complemente;

void solve() {
    std::string s;
    while (fin >> s) {
        if (s.find("S#") != std::string::npos)
            subiecte.push_back(s.substr(2));
        else if (s.find("P#") != std::string::npos)
            predicate.push_back(s.substr(2));
        else
            complemente.push_back(s.substr(2));
    }
    std::sort(subiecte.begin(), subiecte.end());
    std::sort(predicate.begin(), predicate.end());
    std::sort(complemente.begin(), complemente.end());
    for (auto subiect : subiecte)
        for (auto predicat : predicate)
            for (auto complement : complemente)
                fout << subiect << ' ' << predicat << ' ' << complement << '\n';
}

int main() {
    solve();
    fin.close();
    fout.close();
    return 0;
}