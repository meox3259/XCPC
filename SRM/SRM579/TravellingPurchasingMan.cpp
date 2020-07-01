// BEGIN CUT HERE
// END CUT HERE
#line 4 "TravellingPurchasingMan.cpp"
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

class TravellingPurchasingMan {
	public:
	int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
		int m = interestingStores.size();
		vector<int> s(m);
		vector<int> t(m);
		vector<int> dur(m);
		for(int i = 0; i < m; ++i) {
			string tmp = interestingStores[i];
			int x = -1;
			for(int j = 0; j < tmp.size(); ++j) {
				if(tmp[j] == ' ') {
					x = j;
					break;
				}
			}
			for(int j = 0; j < x; ++j) {
				s[i] = s[i] * 10 + tmp[j] - '0';
			}
			int y = -1;
			for(int j = x + 1; j < tmp.size(); ++j) {
				if(tmp[j] == ' ') {
					y = j;
					break;
				}
			}
			for(int j = x + 1; j < y; ++j) {
				t[i] = t[i] * 10 + tmp[j] - '0';
			}
			for(int j = y + 1; j < tmp.size(); ++j) {
				dur[i] = dur[i] * 10 + tmp[j] - '0';
			}
		}

		vector<vector<int> > d(N, vector<int> (N, -1));
		for(int i = 0; i < N; ++i) {
			d[i][i] = 0;
		}

		for(int i = 0; i < roads.size(); ++i) {
			string t = roads[i];
			int x = -1;
			int u = 0;
			int v = 0;
			int w = 0;
			for(int j = 0; j < t.size(); ++j) {
				if(t[j] == ' ') {
					x = j;
					break;
				}
			}
			for(int j = 0; j < x; ++j) {
				u = u * 10 + t[j] - '0';
			}
			int y = -1;
			for(int j = x + 1; j < t.size(); ++j) {
				if(t[j] == ' ') {
					y = j;
					break;
				}
			}
			for(int j = x + 1; j < y; ++j) {
				v = v * 10 + t[j] - '0';
			}
			for(int j = y + 1; j < t.size(); ++j) {
				w = w * 10 + t[j] - '0';
			}
			d[u][v] = w;
			d[v][u] = w;
		}

		for(int k = 0; k < N; ++k) {
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < N; ++j) {
					if(d[i][k] != -1 && d[k][j] != -1 && (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j])) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}

		vector<vector<int> > dp(1 << m, vector<int> (m, inf));
		for(int i = 0; i < m; ++i) {
			if(d[N - 1][i] != - 1 && d[N - 1][i] <= t[i]) {
				dp[1 << i][i] = max(d[N - 1][i], s[i]) + dur[i];
			}
		}

		for(int S = 0; S < 1 << m; ++S) {
			for(int i = 0; i < m; ++i) {
				if(S >> i & 1) {
					for(int j = 0; j < m; ++j) {
						if(!(S >> j & 1)) {
							if(d[i][j] != -1 && dp[S][i] + d[i][j] <= t[j]) {
								dp[S ^ (1 << j)][j] = min(dp[S ^ (1 << j)][j], max(s[j], dp[S][i] + d[i][j]) + dur[j]);
							}
						}
					}
				}
			}
		}

		int ans = 0;
		for(int S = 0; S < 1 << m; ++S) {
			for(int i = 0; i < m; ++i) {
				if(dp[S][i] != inf) {
					ans = max(ans, __builtin_popcount(S));
				}
			}
		}

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"0 1000 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
TravellingPurchasingMan ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
