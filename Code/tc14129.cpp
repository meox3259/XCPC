#include <bits/stdc++.h>
using namespace std;
class BearFair {
	public:
		string isFair(int n, int b, vector <int> A, vector <int> B) {
			int m = A.size(), mx = 0;
			vector<pair<int, int> > v;
			for(int i = 0; i < m; ++i) {
				v.push_back(make_pair(A[i], B[i]));
			}
			v.push_back(make_pair(0, 0));
			v.push_back(make_pair(b, n));
			sort(v.begin(), v.end());
			int mxe = 0, mxo = 0, mxc = 0;
			mxe = min(v[0].first / 2, v[0].second);
			mxo = min((v[0].first + 1) / 2, v[0].second);
			for(int i = 1; i <= m + 1; ++i) {
				if(v[i].second < v[i - 1].second) {
					return "unfair";
				}
				if(v[i].first == v[i - 1].first && v[i].second != v[i - 1].second) {
					return "unfair";
				}
				if(v[i].first - v[i - 1].first < v[i].second - v[i - 1].second) {
					return "unfair";
				}
				mxe += min(v[i].first - v[i - 1].first, v[i].second - v[i - 1].second);
				mxo += min((v[i].first - v[i - 1].first, v[i].second - v[i - 1].second);
//				printf("i = %d mxe = %d mxo = %d\n", i, mxe, mxo);
			}
			return (mxe != n || mxo != n) ? "unfair" : "fair";
		}
} C; /*
int main() {
	int n, b, m;
	cin >> n >> b >> m;
	vector<int> A, B;
	for(int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		A.push_back(x);
		B.push_back(y);
	}
	cout << C.isFair(n, b, A, B);
	return 0;
} */
