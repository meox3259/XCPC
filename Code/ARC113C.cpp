#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    long long ans = 0;
    vector<int> cnt(26);
    for (int i = n - 1; i >= 0; --i) {
        if (i + 2 < n && s[i] == s[i + 1] && s[i + 2] != s[i]) {
            for (int j = 0; j < 26; ++j) {
                if (s[i] - 'a' != j) {
                    cnt[j] = 0;
                }
            }
            ans += n - i - cnt[s[i] - 'a'] - 1;
            cnt[s[i] - 'a'] = n - i;
        } else {
            cnt[s[i] - 'a'] ++;
        }
    }

    cout << ans << '\n';

    return 0;
}
