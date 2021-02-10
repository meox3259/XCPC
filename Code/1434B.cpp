#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int> > opr(n + n);
    for (int i = 0; i < n + n; ++i) {
        char opt;
        cin >> opt;
        if (opt == '+') {
            opr[i] = { 1, 0 };
        } else {
            int x;
            cin >> x;
            x --;
            opr[i] = { -1, x };
        }
    }

    vector<int> ans;
    set<int> s;
    bool ok = true;
    for (int i = n + n - 1; i >= 0; --i) {
        auto [type, j] = opr[i]; 
        if (type == 1) {
            if (s.empty()) {
                ok = false;
                break;
            }
            ans.emplace_back(*s.begin());
            s.erase(s.begin());
        } else {
            if (!s.empty() && *s.begin() < j) {
                ok = false;
                break;
            } else {
                s.emplace(j);
            }
        }
    }

    if (!ok) {
        cout << "NO" << '\n';
        exit(0);
    }

    reverse(ans.begin(), ans.end());
    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
