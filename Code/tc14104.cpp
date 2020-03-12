#include <bits/stdc++.h>
using namespace std;
class FleetFunding {
	public:
		struct node {
			int l, r, cnt;
			node() = default;
			node(int l, int r, int cnt) : l(l), r(r), cnt(cnt) {}
			bool friend operator < (const node &a, const node &b) {
				return a.l == b.l ? a.r > b.r : a.l > b.l;		
			}
		};
 		int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
			int n = k.size();
			auto check = [&](int M) {
				priority_queue<node> q;
				for(int i = 0; i < n; ++i) {
					q.push(node(a[i], b[i], k[i]));
				}
				for(int i = 1; i <= m; ++i) {
					if(q.empty()) {
						return false;
					}
					int sum = 0;
					while(sum < M) {
						if(q.empty() || q.top().l != i) {
							return false;
						}
						if(sum + q.top().cnt < M) {
							sum += q.top().cnt;
							q.pop();
						} else {
							node tmp = q.top();
							q.pop();
							tmp.cnt -= M - sum;
							++tmp.l;
							if(tmp.l <= tmp.r && tmp.cnt) {
								q.push(tmp);
							}
							break;
						}
					}
					while(!q.empty() && q.top().l == i) {
						node tmp = q.top();
						q.pop();
						++tmp.l;
						if(tmp.l <= tmp.r) {
							q.push(tmp);
						}
					}
				}
				return true;
			};
			int l = 0, r = 1e9 + 1, ans = 0;
			while(r - l > 1) {
				int mid = (l + r) >> 1;
				if(check(mid)) {
					l = ans = mid;
				} else {
					r = mid;
				}
			}
			return ans;
		}
}; 
