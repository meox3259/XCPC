#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max() / 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    long long last = 0;
    int cnt = 1;
    vector<vector<int> > par(q + 1, vector<int> (23));
    vector<vector<int> > fa(q + 1, vector<int> (23));
    vector<vector<long long> > Max(q + 1, vector<long long> (23));
    vector<vector<long long> > sum(q + 1, vector<long long> (23));
    vector<long long> v(q + 1);
    v[0] = inf;
    for (int i = 0; i < 23; ++i) {
        sum[0][i] = inf;
        sum[1][i] = inf;
        Max[0][i] = inf;
        Max[1][i] = inf;
    }
    while (q --) {
        int type;
        long long p, q;
        cin >> type >> p >> q;

        if (type == 1) {
            int R = p ^ last;
            long long W = q ^ last;
            cnt ++;
            v[cnt] = W;
            fa[cnt][0] = R;
            Max[cnt][0] = v[R];
            for (int i = 0; i < 22; ++i) {
                fa[cnt][i + 1] = fa[fa[cnt][i]][i];
            }
            for (int i = 0; i < 22; ++i) {
                Max[cnt][i + 1] = max(Max[cnt][i], Max[fa[cnt][i]][i]);
            }

            int cur = cnt;
            for (int i = 22; i >= 0; --i) {
                if (Max[cur][i] < W) {
                    cur = fa[cur][i];
                }
            }

            cur = fa[cur][0];
            par[cnt][0] = cur; 
            sum[cnt][0] = v[cur];
            for (int i = 0; i < 22; ++i) {
                par[cnt][i + 1] = par[par[cnt][i]][i];
            }
            for (int i = 0; i < 22; ++i) {
                sum[cnt][i + 1] = sum[cnt][i] + sum[par[cnt][i]][i];
            }
        }

        if (type == 2) {
            int R = p ^ last;
            long long X = q ^ last;
            if (X < v[R]) {
                last = 0;
                cout << 0 << '\n';
            } else {
                X -= v[R];
                int ans = 1;
                for (int i = 22; i >= 0; --i) {
                    if (sum[R][i] <= X) {
                        ans += 1 << i;
                        X -= sum[R][i];
                        R = par[R][i];
                    }
                }
                last = ans;
                cout << ans << '\n';
            }
        }
    }

    return 0;
}
