#include <bits/stdc++.h>

using namespace std;

const double inf = 1e9;

class FindPolygons {
	public:
	double minimumPolygon(int L) {
		if(L % 2 == 1) {
			return -1.0;
		}

		if(L == 2) {
			return -1.0;
		}

		auto is_sqr = [&] (int x) {
			int y = sqrt(x) + 0.5;
			return y * y == x;
		};

		vector<pair<int, int> > p;

		for(int i = 0; i <= L / 2; ++i) {
			for(int j = 0; i * i + j * j <= L * L; ++j) {
				if(is_sqr(i * i + j * j)) {
					p.emplace_back(i, j);
				}
			}
		}

		double ret = inf;

		for(int i = 0; i < p.size(); ++i) {
			int xa = p[i].first;
			int ya = p[i].second;
			
			for(int j = i + 1; j < p.size(); ++j) {
				int xb = p[j].first;
				int yb = p[j].second;

				int a = sqrt(xa * xa + ya * ya);
				int b = sqrt(xb * xb + yb * yb);
				int c = L - a - b;
	
				if(c > 0 && a + b > c && a + c > b && b + c > a && (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) == c * c) {
					ret = min(ret, 1.0 * max(abs(c - a), max(abs(b - a), abs(b - c))));
				}
			}
		}

		if(ret != inf) {
			return ret;
		}

		if(L % 4 == 0) {
			return 0.0;
		}

		if(L % 2 == 0) {
			return 1.0;
		}

		return -1.0;
	}
};
