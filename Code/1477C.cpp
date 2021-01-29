#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    auto dis = [&] (int i, int j) {
        return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    };

    int u = 0;
    int v = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dis(i, j) > dis(u, v)) {
                u = i;
                v = j;
            } 
        }
    }

    vector<int> ans;
    vector<bool> mark(n);
    ans.emplace_back(u);
    ans.emplace_back(v);
    mark[u] = true;
    mark[v] = true;

    int cur = v;
    for (int _ = 0; _ < n - 2; ++_) {
        int p = cur;
        for (int i = 0; i < n; ++i) {
            if (!mark[i] && dis(cur, i) > dis(cur, p)) {
                p = i; 
            }
        }
        ans.emplace_back(p);
        cur = p;
        mark[p] = true;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
