#include <bits/stdc++.h>

using namespace std;

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

    void add(int p, T val) {
        for(int i = p + 1; i < N; i += (i & -i)) {
            v[i - 1] += val;
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p + 1; i >= 1; i -= (i & -i)) {
            sum += v[i - 1];
        }
        return sum;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<int> > adj(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		x --;
		y --;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> sparse(a);
	sort(sparse.begin(), sparse.end());
	sparse.erase(unique(sparse.begin(), sparse.end()), sparse.end());

	auto id = [&] (int v) {
		return lower_bound(sparse.begin(), sparse.end(), v) - sparse.begin();
	};

	int m = sparse.size();
	vector<vector<int> > pos(m);

	for (int i = 0; i < n; ++i) {
		pos[id(a[i])].emplace_back(i);
	}

	vector<int> in(n);
	vector<int> out(n);
	int dfs_clock = 0;
	auto dfs = [&] (auto &&f, int x, int par) -> void {
		in[x] = dfs_clock ++;
		for (int y : adj[x]) {
			if (y != par) {
				f(f, y, x);
			}
		}
		out[x] = dfs_clock;
	};

	dfs(dfs, 0, -1);

	FenwickTree<int> fw(n + 1);
	vector<int> imos(n + 1);
	for (auto vec : pos) {
		for (int i : vec) {
			fw.add(in[i], 1);
		}
		for (int i : vec) {
			if (fw.query(out[i] - 1) - fw.query(in[i] - 1) != fw.query(n - 1)) {
				imos[in[i]] ++;
				imos[out[i]] --;
			}
		}
		for (int i : vec) {
			for (int j : adj[i]) {
				if (in[j] > in[i] && fw.query(out[j] - 1) - fw.query(in[j] - 1) != 0) {
					imos[0] ++;
					imos[in[j]] --;
					imos[out[j]] ++;
				}
			}
		}
		for (int i : vec) {
			fw.add(in[i], -1);
		}
	}

	for (int i = 0; i < n; ++i) {
		imos[i + 1] += imos[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (imos[i] == 0) {
			ans ++;
		}
	}

	cout << ans << '\n';

	return 0;
}
