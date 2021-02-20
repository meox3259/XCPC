#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<int> > adj(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    queue<int> q; 
    vector<bool> del(n);
    
    auto check = [&] (int x) -> bool {
        bool A = false;
        bool B = false;
        for (int y : adj[x]) {
            if (!del[y] && s[y] == 'A') {
                A = true;
            }
            if (!del[y] && s[y] == 'B') {
                B = true;
            }
        }
        return A && B;
    };

    for (int i = 0; i < n; ++i) {
        if (!check(i)) {
            del[i] = true;
            q.emplace(i);
        }
    }

    int tot = n;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        tot --;
        for (int y : adj[x]) {
            if (!del[y] && !check(y)) {
                del[y] = true;
                q.emplace(y);
            }
        }
    }

    if (tot == 0) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }

    return 0;
}
