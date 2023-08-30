#include <iostream>
#include <queue>

using namespace std;

int n, k, A, B, C, D;
long long current, last;
priority_queue < int > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> A >> B >> C >> D;
    last = A;
    q.push(A);
    for (int i = 2; i <= k; i++) {
        current = (B * last + C) % D;
        q.push(-current);
        last = current;
    }
    for (int i = k + 1; i <= n; i++) {
        current = (B * last + C) % D;
        if (current > -q.top()) {
            q.pop();
            q.push(-current);
        }
        last = current;
    }
    while (!q.empty()) {
        cout << -q.top() << ' ';
        q.pop();
    }
    cout << '\n';
    return 0;
}