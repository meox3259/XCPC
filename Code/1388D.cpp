#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] --;
    }

    vector<int> in(n);
    for (int i = 0; i < n; ++i) {
        if (b[i] >= 0) {
            in[b[i]] ++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.emplace(i);
        }
    }

    long long sum = 0;
    vector<int> ans;
    vector<int> last;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        sum += a[x];
        if (a[x] < 0) {
            last.emplace_back(x); 
        } else {
            ans.emplace_back(x);
            if (b[x] >= 0) {
                a[b[x]] += a[x];
            }
        }
        if (b[x] >= 0) {
            if (-- in[b[x]] == 0) {
                q.emplace(b[x]);
            }
        }
    }

    reverse(last.begin(), last.end());
    for (int i : last) {
        ans.emplace_back(i);
    }

    cout << sum << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
