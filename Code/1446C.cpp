#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > ch(n * 30 + 5, vector<int> (2, -1));
    int tot = 1;

    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 30; j >= 0; --j) {
            int w = a[i] >> j & 1;
            if (ch[cur][w] == -1) {
                ch[cur][w] = tot ++;
            } 
            cur = ch[cur][w];
        }
    }

    int ans = 0;

    auto dfs = [&] (auto &&f, int x, int cur) -> void {
        ans = max(ans, cur + 1);
        if (ch[x][0] != -1) {
            f(f, ch[x][0], cur + (ch[x][1] != -1)); 
        }
        if (ch[x][1] != -1) {
            f(f, ch[x][1], cur + (ch[x][0] != -1));
        }
    };

    dfs(dfs, 0, 0);

    cout << n - ans << '\n';

    return 0;
}
