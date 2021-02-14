#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i] --;
    }

    vector<int> tar(n);
    iota(tar.begin(), tar.end(), 0);

    vector<vector<int> > ans;

    while (c != tar) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (c[j] + 1 == c[i]) {
                    ok = true;
                    vector<vector<int> > seg;
                    vector<int> tmp;
                    if (i != 0) {
                        for (int k = 0; k < i; ++k) {
                            tmp.emplace_back(c[k]);
                        }
                        seg.push_back(tmp);
                        tmp.clear();
                    }
                    int p = i; 
                    while (p + 1 < n && c[p + 1] == c[p] + 1) {
                        p ++;
                    }
                    for (int k = i; k <= p; ++k) {
                        tmp.emplace_back(c[k]);
                    }
                    seg.push_back(tmp);
                    tmp.clear();
                    for (int k = p + 1; k <= j; ++k) {
                        tmp.emplace_back(c[k]);
                    }
                    seg.push_back(tmp);
                    tmp.clear();
                    if (j != n - 1) {
                        for (int k = j + 1; k < n; ++k) {
                            tmp.emplace_back(c[k]);
                        }
                        seg.push_back(tmp);
                    }
                    vector<int> sz;
                    for (auto vec : seg) {
                        sz.emplace_back(vec.size());
                    }
                    ans.push_back(sz);
                    reverse(seg.begin(), seg.end());
                    vector<int> cur;
                    for (auto vec : seg) {
                        for (int k : vec) {
                            cur.emplace_back(k);
                        }
                    }
                    swap(c, cur);
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto vec : ans) {
        cout << vec.size() << ' ';
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " \n"[i + 1 == vec.size()];
        }
    }

    return 0;
}
