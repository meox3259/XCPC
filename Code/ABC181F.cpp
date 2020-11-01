#include <bits/stdc++.h>

using namespace std;

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

	int n;
	cin >> n;

	vector<double> x(n);
	vector<double> y(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	double l = 0.;
	double r = 200.;

	vector<vector<int> > G(n + 2);

	auto dis = [&] (int i, int j) {
		return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	};

	auto check = [&] (double r) {
		int low = n;
		int up = n + 1;
		dsu dsu(n + 2);
		for(int i = 0; i < n; ++i) {
			if(y[i] - r - r <= -100.) {
				dsu.Union(i, low);
			}
			if(y[i] + r + r >= 100.) {
				dsu.Union(i, up);
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i != j) {
					if(dis(i, j) < (r + r) * (r + r)) {
						dsu.Union(i, j);
					}	
				}
			}
		}

		return !dsu.same(low, up);
	};

	for(int i = 0; i < 60; ++i) {
		double mid = (l + r) / 2.;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}

	cout << fixed << setprecision(12);
	cout << l << '\n';

	return 0;
}
