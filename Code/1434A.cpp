#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(6);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<pair<int, int> > p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            p.emplace_back(b[i] - a[j], i);
        }
    }

    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(b[i] - a.back());
    }

    vector<int> cnt(n, 6);

    int ans = inf;
    sort(p.begin(), p.end());
    for (auto [left, i] : p) {
        ans = min(ans, *s.rbegin() - left);
        s.erase(s.find(left));
        cnt[i] --; 
        if (cnt[i] <= 0) {
            break;
        }
        s.emplace(b[i] - a[cnt[i] - 1]);
    }

    cout << ans << '\n';

    return 0;
}
