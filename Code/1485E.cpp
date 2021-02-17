#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<vector<int> > adj(n);
        for (int i = 1; i < n; ++i) {
            int j;
            cin >> j;
            j --;
            adj[i].emplace_back(j);
            adj[j].emplace_back(i);
        } 

        vector<int> a(n);
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
        }

        queue<int> q;
        q.emplace(0);

        vector<int> d(n, -1);
        d[0] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.emplace(y);
                }
            }
        }

        int m = *max_element(d.begin(), d.end()) + 1;
        vector<vector<int> > node(m);
        for (int i = 0; i < n; ++i) {
            node[d[i]].emplace_back(i);
        }

        for (int i = 0; i < m; ++i) {
            sort(node[i].begin(), node[i].end(), [&] (int i, int j) {
                return a[i] < a[j];
            });
        }

        vector<long long> dp(n);
        for (int i = 0; i < m; ++i) {
            auto vec = node[i];
            for (int j : vec) {
                for (int k : adj[j]) {
                    dp[k] = max(dp[k], dp[j] + max(abs(a[vec[0]] - a[j]), abs(a[vec.back()] - a[j])));
                } 
            }
            long long Max = -inf;
            for (int j : vec) {
                Max = max(Max, dp[j] - a[j]);
                for (int k : adj[j]) {
                    dp[k] = max(dp[k], a[j] + Max);
                }
            }
            reverse(vec.begin(), vec.end());
            Max = -inf;
            for (int j : vec) {
                Max = max(Max, dp[j] + a[j]);
                for (int k : adj[j]) {
                    dp[k] = max(dp[k], -a[j] + Max);
                }
            }
        }

        long long ans = 0;
        auto vec = node.back();
        for (int i : vec) {
            ans = max(ans, dp[i] + max(abs(a[i] - a[vec[0]]), abs(a[i] - a[vec.back()])));
        }

        cout << ans << '\n';
    }

    return 0;
}
