#include <iostream>
#include <deque>

using namespace std;

int N, K, W;
long long M, s[1000005];
deque<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K >> W;
    int i, x;
    for (i = 1; i <= N; i++) {
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    M = s[K];
    q.push_back(0);
    for (i = K + 1; i <= N; i++) {
        // Introducem valoarea i - k
        while (!q.empty() && s[q.back()] >= s[i - K])
            q.pop_back();
        q.push_back(i - K);
        if (q.front() == i - W - 1)
            q.pop_front();
        M = max(M, s[i] - s[q.front()]);
    }
    cout << M << '\n';
    return 0;
}