#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        long long W;
        cin >> n >> W;

        vector<long long> w(n);
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&] (int i, int j) {
            return w[i] < w[j];
        });

        while (!id.empty() && w[id.back()] > W) {
            id.pop_back();
        }

        long long sum = 0;
        vector<int> ans;

        while (!id.empty() && sum < (W + 1) / 2) {
            sum += w[id.back()];
            ans.emplace_back(id.back());
            id.pop_back();
        }

        if (sum < (W + 1) / 2) {
            cout << -1 << '\n';
            continue;
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
        }
    }

    return 0;
}
