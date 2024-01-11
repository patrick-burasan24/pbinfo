#include <bits/stdc++.h>

using namespace std;

string s;

bool nextInteger(int currentPosition) {
    for (int i = currentPosition + 1; i < s.size(); i++) 
        if (s[i] >= '0' && s[i] <= '9')
            return true;
    return false;
}

void solve() {
    string nums;
    string chars;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            continue;
        if (!nums.size() && s[i] == '0') {
            if (nextInteger(i)) {
                chars += s[i];
                continue;
            }
            nums += s[i];
        } else if (s[i] >= '0' && s[i] <= '9')
            nums += s[i];
        else
            chars += s[i];
    }
    if (!chars.size() && nums.size())
        cout << "CORECT\n";
    else if (chars.size() && !nums.size())
        cout << "NaN\n";
    else {
        cout << nums << '\n';
        for (auto character : chars)
            cout << character << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s);
    solve();
    return 0;
}