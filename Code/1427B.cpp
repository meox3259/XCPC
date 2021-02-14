#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = 0;
        int len = 0;
        for (char c : s) {
            if (c == 'W') {
                len ++;
            } else {
                if (len != 0) {
                    ans += len * 2 - 1;
                    len = 0;
                }
            }
        }

        if (len != 0) {
            ans += len * 2 - 1;
            len = 0;
        }

        int cur = 0;
        int tot = 0;
        vector<int> seg;
        while (!s.empty() && s.back() == 'L') {
            tot ++;
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        while (!s.empty() && s.back() == 'L') {
            tot ++;
            s.pop_back();
        }
        if (tot == n) {
            cout << max(0, min(k, n) * 2 - 1) << '\n';
            continue;
        }
        for (char c : s) {
            if (c == 'L') {
                cur ++;
            } else {
                if (cur > 0) {
                    seg.emplace_back(cur);
                    cur = 0;
                }
            }
        }
        sort(seg.begin(), seg.end());
        for (int i : seg) {
            if (k >= i) {
                k -= i;
                ans += 2 * i + 1;
            } else {
                ans += 2 * k; 
                k = 0;
                break;
            }
        }

        ans += min(k, tot) * 2;
        cout << ans << '\n';
    }

    return 0;
}
