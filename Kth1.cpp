#include <bits/stdc++.h>

using namespace std;

int N, K, L, Q;
multiset<int> smin, smax;
multiset<int> :: iterator it;
multiset<int> :: reverse_iterator rit;
vector<int> a, ans;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> L;
    a.resize(N + 1);
    ans.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    
    for (int i = 1; i <= L; i++)
        smax.insert(a[i]);

    for (int i = 1; i <= K; i++)
    {
        it = smax.begin();
        smin.insert(*it);
        smax.erase(smax.find(*it));
    }

    ans[1] = *smin.rbegin();

    for (int i = L + 1; i <= N; i++)
    {
        // Eliminam elementul a[i - L]
        if (smin.find(a[i - L]) != smin.end())
            smin.erase(smin.find(a[i - L]));
        else
            smax.erase(smax.find(a[i - L]));

        // Adaugam elementul a[i]
        if (smin.size() && *smin.rbegin() <= a[i])
            smax.insert(a[i]);
        else
            smin.insert(a[i]);

        while (smin.size() > K)
        {
            rit = smin.rbegin();
            smax.insert(*rit);
            smin.erase(smin.find(*rit));
        }

        while (smax.size() > L - K)
        {
            it = smax.begin();
            smin.insert(*it);
            smax.erase(smax.find(*it));
        }

        ans[i - L + 1] = *smin.rbegin();
    }

    cin >> Q;
    while (Q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}