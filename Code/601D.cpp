#include <bits/stdc++.h>

using namespace std;

namespace Trie {
    vector<vector<int> > child;
    vector<int> sum;
    vector<int> root;
    void init(int n) {
        root.resize(n); 
        child.push_back(vector<int> (26));
        sum.push_back(0);
    }
    int NewNode() {
        child.push_back(vector<int> (26));
        sum.push_back(0);
        return (int)child.size() - 1;
    }
    int merge(int x, int y) {
        if (x == 0 || y == 0) {
            return x | y;
        }
        int z = NewNode();
        for (int i = 0; i < 26; ++i) {
            child[z][i] = merge(child[x][i], child[y][i]);
        }
        for (int i = 0; i < 26; ++i) {
            sum[z] += sum[child[z][i]] + (child[z][i] != 0);
        }
        return z;
    }

    void add(int c, int x) {
        int tmp = root[x];
        int cur = NewNode();
        child[cur][c] = root[x];
        sum[cur] = sum[root[x]] + 1;
        root[x] = cur;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using namespace Trie;

    int n;
    cin >> n;

    init(n);

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];        
    }

    string s;
    cin >> s;

    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    unordered_map<int, int> mp;
    int ans = 0;
    int Max = 0;
    auto dfs = [&] (auto &&f, int x, int par) -> void {
        root[x] = NewNode();
        for (int y : adj[x]) {
            if (y != par) {
                f(f, y, x);
                root[x] = merge(root[x], root[y]);
            }
        }
        add(s[x] - 'a', x);
        if (c[x] + sum[root[x]] > Max) {
            Max = c[x] + sum[root[x]];
            ans = 1;
        } else if (c[x] + sum[root[x]] == Max) {
            ans ++;
        }
    };

    dfs(dfs, 0, -1);

    cout << Max << '\n';
    cout << ans << '\n';

    return 0;
}
