#include <bits/stdc++.h>

using namespace std;

multiset<int> s;
int N, op, x;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while (N--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            s.insert(x);
        }
        else if (op == 2)
        {
            cin >> x;
            if (s.count(x) > 0)
                s.erase(x);
        }
        else
        {
            if (s.empty())
                cout << "-1\n";
            else
                cout << *s.begin() << ' ' << s.count(*s.begin()) << '\n';
        }
    }
    return 0;
}