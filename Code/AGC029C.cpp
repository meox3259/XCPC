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

    int l = 0;
    int r = n + 1;

    auto check = [&] (int x) -> bool {
        vector<pair<int, int> > s;
        s.emplace_back(a[0], 0);
        for (int i = 1; i < n; ++i) {
            if (a[i] <= a[i - 1]) {
                auto last = s.back();
                while (!s.empty() && s.back().first >= a[i]) {
                    last = s.back();
                    s.pop_back();
                }
                if (a[i] > 1 && (s.empty() || (s.back().first != a[i] - 1))) {
                    s.emplace_back(a[i] - 1, last.second);
                }
                s.emplace_back(a[i], last.second + 1);
                if (s.back().second >= x) {
                    int j = (int)s.size() - 1;
                    vector<pair<int, int> > st;
                    while (!s.empty() && s.back().second >= x) {
                        s.pop_back();
                        if (s.empty()) {
                            return false;
                        }
                        s.back().second ++;
                    }
                    auto b = s.back();
                    s.pop_back();
                    b.first --;
                    b.second --;
                    if (b.first >= 1 && (s.empty() || s.back().first != b.first)) {
                        s.push_back(b);
                    }
                    s.emplace_back(b.first + 1, b.second + 1); 
                    if (s.back().first != a[i]) {
                        s.emplace_back(a[i], 0);
                    }
                }
            }
            if (a[i] > a[i - 1]) {
                s.emplace_back(a[i], 0);
            }
        }
        return true;
    };

    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << '\n';

    return 0;
}
