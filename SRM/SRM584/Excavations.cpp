// BEGIN CUT HERE
// END CUT HERE
#line 4 "Excavations.cpp"
#include <bits/stdc++.h>

using namespace std;

long long c[55][55];

class Excavations {
	public:
	long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
		c[0][0] = 1;
		for(int i = 1; i <= 50; ++i) {
			c[i][0] = 1;
			for(int j = 1; j <= i; ++j) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}

		auto find = [&] (int x) {
			for(int i : found) {
				if(x == i) {
					return true;
				}
			}
			return false;
		};

		int n = kind.size();
		vector<int> d;

		for(int i = 0; i < n; ++i) {
			if(!find(kind[i])) {
				d.emplace_back(depth[i]);
			}
		}

		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());

		int m = found.size();
		long long ans = 0;
		
		for(int p : d) {
			vector<int> cnt(51);
			for(int i = 0; i < n; ++i) {
				if(depth[i] < p && find(kind[i])) {
					for(int j = 0; j < m; ++j) {
						if(kind[i] == found[j]) {
							cnt[j] += 1;
						}
					}
				}
			}
			for(int i = 0; i < n; ++i) {
				if(depth[i] == p && !find(kind[i])) {
					cnt[m] += 1;
				}
			}

			vector<vector<long long> > dp(m + 2, vector<long long> (51, 0));
			dp[0][0] = 1;
			for(int i = 0; i <= m; ++i) {
				for(int j = 0; j <= n; ++j) {
					for(int k = 1; k <= cnt[i] && k + j <= n; ++k) {
						dp[i + 1][j + k] += dp[i][j] * c[cnt[i]][k];
					}
				}
			}
			int tot = 0;
			for(int i = 0; i < n; ++i) {
				if(depth[i] > p || (depth[i] == p && find(kind[i]))) {
					tot += 1;
				}
			}

			for(int i = m + 1; i <= K; ++i) {
				ans += dp[m + 1][i] * c[tot][K - i]; 
			}
		}

		vector<int> cnt(51, 0);
		vector<vector<long long> > dp(m + 1, vector<long long> (51, 0));
		for(int i : kind) {
			for(int j = 0; j < m; ++j) {
				if(i == found[j]) {
					cnt[j] += 1;
				}
			}
		}
		dp[0][0] = 1;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j <= n; ++j) {
				for(int k = 1; k <= cnt[i] && k + j <= n; ++k) {
					dp[i + 1][j + k] += dp[i][j] * c[cnt[i]][k];
				}
			}
		}

		ans += dp[m][K];
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 3LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 4LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; long long Arg4 = 0LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 2, 3, 1, 3, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; long long Arg4 = 35LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 18; long long Arg4 = 9075135300LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
Excavations ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
