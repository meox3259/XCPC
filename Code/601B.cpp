#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q --) {
        int l, r;
        cin >> l >> r;
        l --;
        r --;
        vector<int> tmp;
        for (int i = l; i <= r; ++i) {
            tmp.emplace_back(a[i]);
        }

        auto solve = [&] (vector<int> a) -> long long {
            vector<long long> h;
            int n = a.size();
            for (int i = 0; i < n - 1; ++i) {
                h.emplace_back(abs(a[i] - a[i + 1]));
            }
            long long ret = 0;
            vector<pair<long long, int> > st;
            for (int i = 0; i < n - 1; ++i) {
                while (!st.empty() && h[i] >= h[st.back().second]) {
                    st.pop_back();
                }
                int pre = st.empty() ? -1 : st.back().second;
                long long sum = st.empty() ? h[i] * (i - pre) : h[i] * (i - pre) + st.back().first;
                ret += sum;
                st.emplace_back(sum, i);
            }
            return ret;
        };

        cout << solve(tmp) << '\n';
    }

    return 0;
}
