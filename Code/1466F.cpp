#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

class dsu {
    private:
    vector<int> par;

    public:
    dsu(int N) : par(N) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void Union(int x, int y) {
        if(same(x, y)) {
            return;
        }
 
        x = find(x);
        y = find(y);
        par[x] = y;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	dsu dsu(m);

	long long tot = 1;
	vector<int> ans;
	vector<int> vis(m);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		if (k == 1) {
			int x;
			cin >> x;
			x --;
			if (!vis[dsu.find(x)]) {
				ans.emplace_back(i);
				tot = tot * 2 % P;
				vis[dsu.find(x)] = 1;
			}
		} else {
			int x, y;
			cin >> x >> y;
			x --;
			y --;
			if ((!vis[dsu.find(x)] || !vis[dsu.find(y)]) && !dsu.same(x, y)) {
				int t = vis[dsu.find(x)] | vis[dsu.find(y)];
				dsu.Union(x, y);
				ans.emplace_back(i);
				tot = tot * 2 % P;
				vis[dsu.find(x)] |= t;
			}
		}
	}

	cout << tot << ' ' << ans.size() << '\n';
	for (int i : ans) {
		cout << i + 1 << ' ';
	}
	cout << '\n';

	return 0;
}
