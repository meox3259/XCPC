#include <bits/stdc++.h>
using namespace std;
class MoveStones {
	public:
		long long get(vector <int> a, vector <int> b) {
			int n = a.size();
			long long sum = 0;
			for(int i = 0; i < n; ++i) {
				sum += a[i] - b[i];
			}
			if(sum != 0) {
				return -1;
			}
			if(n == 1) {
				return 0;
			}
			long long ans = numeric_limits<long long> :: max();
			for(int j = 0; j < n; ++j) {
				long long sum = 0;
				long long pre = 0;
				for(int i = 0; i < n; ++i) {
					pre += a[(i + j) % n] - b[(i + j) % n];
					sum += abs(pre); 
				}
				ans = min(ans, sum);
			}
			return ans;
		}
};
