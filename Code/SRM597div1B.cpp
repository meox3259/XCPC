#include <bits/stdc++.h>

using namespace std;

class ConvexPolygonGame {
	public:
	string winner(vector <int> x, vector <int> y) {
		int n = x.size();

		long long side = 0;
		long long s = 0;

		auto area = [&] (int x1, int y1, int x2, int y2) {
			return 1LL * x1 * y2 - 1LL * x2 * y1;
		};

		auto pos = [&] (int x1, int y1, int x2, int y2, int x) {			
			return 1.0 * y1 + 1.0 * (y2 - y1) / (x2 - x1) * (x - x1); 
		};

		for(int i = 0; i < n; ++i) {
			side += __gcd(abs(x[(i + 1) % n] - x[i]), abs(y[(i + 1) % n] - y[i]));
			s += area(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
		}
		
		s = abs(s);
		
		long long cnt = side + (s + 2 - side) / 2 - n; //pick theory
		
		if(cnt > 200001) {
			return "Masha";
		}

		if(cnt < 3) {
			return "Petya";
		}

		vector<pair<int, int> > p;
		p.resize(200005);

		int base = 100000;

		for(int i = 0; i < n; ++i) {
			int x1 = x[i];
			int x2 = x[(i + 1) % n];
			int y1 = y[i];
			int y2 = y[(i + 1) % n];

			if(x1 == x2) {
				p[x1 + base] = {min(y1, y2) + 1, max(y1, y2) - 1};
			}

			if(x1 < x2) {
				for(int j = x1 + 1; j < x2; ++j) {
					p[j + base].first = ceil(pos(x1, y1, x2, y2, j));
				}

				p[x1 + base].first = y1 + 1;
				p[x2 + base].first = y2 + 1;
			}

			if(x1 > x2) {
				for(int j = x2 + 1; j < x1; ++j) {
					p[j + base].second = floor(pos(x2, y2, x1, y1, j));
				}

				p[x1 + base].second = y1 - 1;
				p[x2 + base].second = y2 - 1;
			}
		}

		int x1 = *min_element(x.begin(), x.end());
		int x2 = *max_element(x.begin(), x.end());

		vector<pair<int, int> > points;

		for(int i = x1; i <= x2; ++i) {
			for(int j = p[i + base].first; j <= p[i + base].second; ++j) {
				points.emplace_back(i, j);
			}
		}

		for(int i = 2; i < points.size(); ++i) {
			if(area(points[i].first - points[0].first, points[i].second - points[0].second, points[1].first - points[0].first, points[1].second - points[0].second) != 0) {
				return "Masha";
			}
		}

		return "Petya";
	}
};
