#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] --;
        }

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[a[i]] = i;
        }

        vector<int> b(k);
        for (int i = 0; i < k; ++i) {
            cin >> b[i];
            b[i] --;
        }

        vector<int> pre(n, -1);
        vector<int> nxt(n, -1);
        for (int i = 1; i < n; ++i) {
            pre[i] = i - 1;
        }
        for (int i = 0; i < n - 1; ++i) {
            nxt[i] = i + 1;
        }

        vector<bool> mark(n);
        for (int i : b) {
            mark[pos[i]] = true;
        }

        long long ans = 1;

        for (int i = 0; i < k; ++i) {
            int j = pos[b[i]];
            int cnt = 0;
            if (pre[j] != -1 && !mark[pre[j]]) {
                cnt ++;
            }
            if (nxt[j] != -1 && !mark[nxt[j]]) {
                cnt ++;
            }
            ans = ans * cnt % P;
            if (pre[j] != -1) {
                nxt[pre[j]] = nxt[j];
            }
            if (nxt[j] != -1) {
                pre[nxt[j]] = pre[j];
            }
        } 

        cout << ans << '\n';
    }

    return 0;
}
