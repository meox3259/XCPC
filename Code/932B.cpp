#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> mp(1000001, -1);

    auto f = [&] (int x) -> int {
        int ret = 1;
        while (x) {
            if (x % 10 != 0) {
                ret = ret * (x % 10);
            }
            x /= 10;
        }
        return ret;
    };

    auto g = [&] (auto &&ff, int x) -> int {
        if (x < 10) {
            return x;
        }
        if (mp[x] != -1) {
            return mp[x];
        }
        return mp[x] = ff(ff, f(x));
    };

    vector<vector<int> > pre(1000001, vector<int> (10));
    for (int i = 1; i <= 1000000; ++i) {
        pre[i] = pre[i - 1];
        pre[i][g(g, i)] ++;
    }

    int q;
    cin >> q;

    while (q --) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pre[r][k] - pre[l - 1][k] << '\n';
    }

    return 0;
}
