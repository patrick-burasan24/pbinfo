#include <bits/stdc++.h>

using namespace std;

string s;
string sol;

void solve() {
    while (s.size()) {
        string temp;
        for (int i = 0; i < s.size(); i++) {
            temp += s[i];
            if (s.find(temp, 1) != string::npos) {
                if (sol.size() < temp.size()) 
                    sol = temp;
                else if (sol.size() == temp.size() && temp < sol)
                    sol = temp;
            }
        }
        s = s.substr(1);
    }
    cout << sol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    solve();
    return 0;
}