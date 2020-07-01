// BEGIN CUT HERE
// END CUT HERE
#line 4 "WolfInZooDivOne.cpp"
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

class WolfInZooDivOne {
	public:
	int count(int N, vector <string> L, vector <string> R) {
		string s = "";
		for(auto o : L) {
			s += o;
		}

		string t = "";
		for(auto o : R) {
			t += o;
		}

		int last = -1;
		s += " ";
		vector<int> l;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == ' ') {
				int v = 0;
				for(int j = last + 1; j < i; ++j) {
					v = v * 10 + s[j] - '0';
				}
				l.emplace_back(v);
				last = i;
			}
		}

		last = -1;
		t += " ";
		vector<int> r;
		for(int i = 0; i < t.size(); ++i) {
			if(t[i] == ' ') {
				int v = 0;
				for(int j = last + 1; j < i; ++j) {
					v = v * 10 + t[j] - '0';
				}
				r.emplace_back(v);
				last = i;
			}
		}

		int m = l.size();

		vector<vector<int> > seg(N, vector<int> (N));
		for(int i = 0; i < N; ++i) {
			for(int j = i; j < N; ++j) {
				for(int k = 0; k < m; ++k) {
					if(j <= r[k] && i >= l[k]) {
						seg[i][j] = 1;
					}
				}
			}
		}
	
		int cur = 0;
		vector<vector<vector<int> > > dp(2, vector<vector<int> > (N + 1, vector<int> (N + 1)));
		dp[cur][0][0] = 1;
		for(int i = 0; i < N; ++i) {
			cur ^= 1;
			for(int j = 0; j <= N; ++j) {
				for(int k = 0; k <= N; ++k) {
					dp[cur][j][k] = dp[cur ^ 1][j][k];
				}
			}
			for(int j = 0; j <= i; ++j) {
				for(int k = j; k <= i; ++k) {
					int cnt = (j != 0) + (k != 0);
					if(cnt < 2) {
						dp[cur][k][i + 1] = (dp[cur][k][i + 1] + dp[cur ^ 1][j][k]) % P;
					} else if(!seg[j - 1][i]) {
						dp[cur][k][i + 1] = (dp[cur][k][i + 1] + dp[cur ^ 1][j][k]) % P;
					}
				}
			}
		}

		int ans = 0;
		for(int i = 0; i <= N; ++i) {
			for(int j = 0; j <= N; ++j) {
				ans = (ans + dp[cur][i][j]) % P;
			}
		}

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"0 4 2 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 9 5 9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 225; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; string Arr1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6419882; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
WolfInZooDivOne ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
