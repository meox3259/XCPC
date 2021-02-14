#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    map<string, int> id;
    for (int i = 0; i < n; ++i) {
        id[s[i]] = i;
    }

    vector<string> t(m);
    vector<int> mt(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> mt[i]; 
        mt[i] --;
    }

    bool ok = true;
    map<string, int> fi;
    vector<vector<int> > adj(n);
    vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        vector<int> vec;
        for (int S = 0; S < 1 << k; ++S) {
            string tmp(k, '_');
            for (int j = 0; j < k; ++j) {
                if (S >> j & 1) {
                    tmp[j] = '_'; 
                } else {
                    tmp[j] = t[i][j];
                }
            } 
            if (id.find(tmp) != id.end()) {
                vec.emplace_back(id[tmp]); 
            }
        }
        bool hav = false;
        for (int j : vec) {
            if (j == mt[i]) {
                hav = true;
            }
        }
        if (!hav) {
            ok = false;
            break;
        }
        for (int j : vec) {
            if (j != mt[i]) {
                adj[mt[i]].emplace_back(j);
                in[j] ++;
            }
        }
    }

    if (!ok) {
        cout << "NO" << '\n';
        exit(0);
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.emplace(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.emplace_back(x);
        for (int y : adj[x]) {
            if (! --in[y]) {
                q.emplace(y);
            }
        }
    }

    if (ans.size() < n) {
        cout << "NO" << '\n';
        exit(0);
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
