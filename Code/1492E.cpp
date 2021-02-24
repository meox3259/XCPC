#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > s(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
        }
    }

    vector<int> cnt(n);
    vector<vector<int> > diff(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != s[0][j]) {
                cnt[i] += s[i][j] != s[0][j];
                diff[i].emplace_back(j);
            }
        }
    }

    if (*max_element(cnt.begin(), cnt.end()) > 4) {
        cout << "No" << '\n';
        exit(0);
    }

    vector<vector<int> > vec(5);
    for (int i = 0; i < n; ++i) {
        vec[cnt[i]].emplace_back(i);
    }

    auto check = [&] (vector<int> ans) -> bool {
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt[i] += (s[i][j] != ans[j]);
            }
        }
        return *max_element(cnt.begin(), cnt.end()) <= 2;
    };

    if (vec[4].empty() && vec[3].empty()) {
        cout << "Yes" << '\n';
        for (int i = 0; i < m; ++i) {
            cout << s[0][i] << " \n"[i == m - 1];
        }
        exit(0);
    }

    if (!vec[4].empty()) {
        int r = vec[4].back();
        for (int a = 0; a < diff[r].size(); ++a) {
            for (int b = a + 1; b < diff[r].size(); ++b) {
                vector<int> tmp(m);
                for (int i = 0; i < m; ++i) {
                    tmp[i] = s[0][i];
                }
                tmp[diff[r][a]] = s[r][diff[r][a]];
                tmp[diff[r][b]] = s[r][diff[r][b]];
                if (check(tmp)) {
                    cout << "Yes" << '\n';
                    for (int i = 0; i < m; ++i) {
                        cout << tmp[i] << " \n"[i == m - 1];
                    }
                    exit(0);
                }
            }
        }
        cout << "No" << '\n';
        exit(0);
    } 

    if (!vec[3].empty()) {
        int r = vec[3].back(); 
        for (int a = 0; a < diff[r].size(); ++a) {
            vector<int> tmp(m);
            for (int i = 0; i < m; ++i) {
                tmp[i] = s[0][i];
            }
            tmp[diff[r][a]] = s[r][diff[r][a]];
            if (check(tmp)) {
                cout << "Yes" << '\n';
                for (int i = 0; i < m; ++i) {
                    cout << tmp[i] << " \n"[i == m - 1];
                }
                exit(0);
            }
        }
   
        for (int a = 0; a < diff[r].size(); ++a) {
            for (int b = a + 1; b < diff[r].size(); ++b) {
                vector<int> tmp(m);
                for (int i = 0; i < m; ++i) {
                    tmp[i] = s[0][i];
                }
                tmp[diff[r][a]] = s[r][diff[r][a]];
                tmp[diff[r][b]] = s[r][diff[r][b]];
                if (check(tmp)) {
                    cout << "Yes" << '\n';
                    for (int i = 0; i < m; ++i) {
                        cout << tmp[i] << " \n"[i == m - 1];
                    }
                    exit(0);
                }
            }
        }
        for (int a : diff[r]) {
            vector<int> tmp(s[0]);
            tmp[a] = s[r][a];
            int b = -1;
            vector<int> cur;
            vector<int> cnt(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cnt[i] += (s[i][j] != tmp[j]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (cnt[i] >= 3) {
                    cur.emplace_back(i);
                }
            }
            for (int i : cur) {
                bool ok = false;
                unordered_map<int, int> hav;
                for (int j : diff[r]) {
                    hav[j] = true;
                }
                if (i != r) {
                    for (int j : diff[i]) {
                        if (j != a && s[i][j] != s[r][j] && hav.count(j)) {
                            tmp[j] = s[i][j];
                            if (check(tmp)) {
                                cout << "Yes" << '\n';
                                for (int i = 0; i < m; ++i) {
                                    cout << tmp[i] << " \n"[i == m - 1];
                                }
                                exit(0);
                            } else {
                                ok = true;
                                break;
                            }
                        }   
                    }
                }
                if (ok) {
                    break;
                }
            }  
        }
    }

    cout << "No" << '\n';

    return 0;
}
