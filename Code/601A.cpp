#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > da(n, vector<int> (n, inf));
    vector<vector<int> > db(n, vector<int> (n, 1));
    for (int i = 0; i < n; ++i) {
        da[i][i] = db[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        da[x][y] = da[y][x] = 1;
        db[x][y] = db[y][x] = inf;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                da[i][j] = min(da[i][j], da[i][k] + da[k][j]);
                db[i][j] = min(db[i][j], db[i][k] + db[k][j]);
            }
        }
    }

    if (da[0][n - 1] == inf || db[0][n - 1] == inf) {
        cout << -1 << '\n';
    } else {
        cout << max(da[0][n - 1], db[0][n - 1]) << '\n';
    }

    return 0;
}
