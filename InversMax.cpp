#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

string buildWord(const string &str, int l, int r) {
    string outputString;
    for (size_t i = l; i <= r; i++)
        outputString += str[i];
    return outputString;
}

bool isWord(const string &str) {
    for (auto chr : str)
        if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
            return true;
    return false;
}

string s;
string sol;

void solve() {
    int maximumStringSize = -INF;
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] != ' ') {
            size_t pos = s.find(' ', i);
            string word;
            if (pos != string::npos)
                word = buildWord(s, i, pos - 1);
            else
                word = buildWord(s, i, s.size() - 1);
            if (isWord(word))
                maximumStringSize = max(maximumStringSize, (int)word.size());
            i = pos - 1;
        }
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] != ' ') {
            size_t pos = s.find(' ', i);
            string word;
            if (pos != string::npos)
                word = buildWord(s, i, pos - 1);
            else
                word = buildWord(s, i, s.size() - 1);
            if (word.size() == maximumStringSize && isWord(word))
                reverse(word.begin(), word.end());
            sol += word;
            i = pos - 1;
        } else
            sol += s[i];
    cout << sol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s);
    solve();
    return 0;
}