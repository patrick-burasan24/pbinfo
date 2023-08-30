#include <iostream>
#include <queue>

using namespace std;

int n, x, y, cost;
priority_queue < int > q;

void Citire() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        q.push(-x);
    }
}

void Procesare() {
    if (n == 1) {
        cost = -q.top();
        q.pop();
    }
    while (!q.empty()) {
        x = -q.top();
        q.pop();
        if (!q.empty()) {
            y = -q.top();
            q.pop();
            x += y;
            q.push(-x);
            cost += x;
        }
    }
}

void Afisare() {
    cout << cost << '\n';
}

int main() {
    Citire();
    Procesare();
    Afisare();
    return 0;
}