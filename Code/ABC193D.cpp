#include <bits/stdc++.h>

using namespace std;

#define double long double

int main() {
    int k;
    cin >> k;

    string s, t;
    cin >> s >> t;

    vector<int> cnt(10, k);
    for (char c : s) {
        if (c != '#') {
            cnt[c - '0'] --;
        }
    }
    for (char c : t) {
        if (c != '#') {
            cnt[c - '0'] --;
        }
    }

    int x = 0;
    int y = 0;
    for (int i = 3; i >= 0; --i) {
        x = x * 10 + s[i] - '0';
    }
    for (int i = 3; i >= 0; --i) {
        y = y * 10 + t[i] - '0';
    }

    double ans = 0.;
    cout << fixed << setprecision(15);

    vector<int> ten(10);
    ten[0] = 1;
    for (int i = 1; i < 10; ++i) {
        ten[i] = ten[i - 1] * 10;
    }

    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            auto calc = [&] (int i, int j) -> bool {
                vector<int> tot_1(10);
                vector<int> tot_2(10);
                vector<int> tot(10);
                tot_1[i] ++;
                tot_2[j] ++;
                tot[i] ++;
                tot[j] ++;
                for (char c : s) {
                    if (c != '#') {
                        tot[c - '0'] ++;
                        tot_1[c - '0'] ++;
                    }
                }
                for (char c : t) {
                    if (c != '#') {
                        tot[c - '0'] ++;
                        tot_2[c - '0'] ++;
                    }
                }
                int x = 0;
                int y = 0;
                for (int k = 1; k < 10; ++k) {
                    x += k * ten[tot_1[k]];
                    y += k * ten[tot_2[k]];
                }
                return x > y;
            };
            if (((i != j && cnt[i] >= 1 && cnt[j] >= 1) || (i == j && cnt[i] >= 2)) && calc(i, j)) {
                if (i == j) {
                    ans += 1. * cnt[i] * (cnt[i] - 1) / (9. * k - 8) / (9. * k - 9);
                } else {
                    ans += 1. * cnt[i] * cnt[j] / (9. * k - 8) / (9. * k - 9);
                }
            } 
        }
    }

    cout << ans << '\n';

    return 0;
}
