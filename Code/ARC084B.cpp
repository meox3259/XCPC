#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    int k;
    cin >> k;

    vector<vector<pair<int, int> > > adj(k); 
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < 10; ++j) {
            adj[i].emplace_back((i * 10 + j) % k, j);
        }         
    }

    vector<int> d(k, inf);
    for (int i = 1; i < min(k, 10); ++i) {
        d[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    for (int i = 1; i < min(k, 10); ++i) {
        q.emplace(d[i], i);
    }

    while (!q.empty()) {
        auto [cur, x] = q.top();
        q.pop();
        if (cur > d[x]) {
            continue;
        }
        for (auto [y, w] : adj[x]) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                q.emplace(d[y], y);
            }
        }
    }

    cout << d[0] << '\n';

    return 0;
}

