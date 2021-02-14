#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l;
    cin >> n >> l;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int m = 0;
    for (auto t : s) {
        m += t.size();
    }

    vector<vector<int> > ch(m * 2, vector<int> (2, -1));
    vector<bool> ban(m * 2);
    vector<int> dep(m * 2);
    int tot = 1;
    int root = 0;
    for (int i = 0; i < n; ++i) {
        int cur = root;
        for (int j = 0; j < s[i].size(); ++j) {
            int c = s[i][j] - '0'; 
            if (ch[cur][c] == -1) {
                ch[cur][c] = tot ++;
                dep[ch[cur][c]] = dep[cur] + 1;
            } 
            cur = ch[cur][c];
        }
        ban[cur] = true;
    }

    vector<int> cnt(64);
    int sum = 0;
    for (int i = 0; i < tot; ++i) {
        if (!ban[i]) {
            for (int j = 0; j < 2; ++j) {
                if (ch[i][j] == -1 && dep[i] < l) {
                    long long d = l - dep[i];
                    int bit = 0;
                    while (d % 2 == 0) {
                        d /= 2;
                        bit ++;
                    }
                    cnt[bit] ++;
                }
            }
        }
    }

    bool odd = false;
    for (int i : cnt) {
        if (i & 1) {
            odd = true;
        }
    }

    if (odd) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }

    return 0;
}
