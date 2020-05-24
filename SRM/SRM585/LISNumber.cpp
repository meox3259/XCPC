// BEGIN CUT HERE
// END CUT HERE
#line 4 "LISNumber.cpp"
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

long long power(long long x, long long t) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

class LISNumber {
	public:
	int count(vector <int> cardsnum, int K) {
		int n = cardsnum.size();
		int m = 0;
		for(int i : cardsnum) {
			m += i;
		}
		vector<vector<long long> > c(m + 1, vector<long long> (m + 1));
		c[0][0] = 1;
		for(int i = 1; i <= m; ++i) {
			c[i][0] = 1;
			for(int j = 1; j <= i; ++j) {
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
			}
		}
		vector<vector<long long> > dp(n + 1, vector<long long> (m + 1, 0));
		dp[0][0] = 1;
		int cur = 0;
		for(int i = 0; i < n; ++i) {
			int v = cardsnum[i];
			for(int j = 0; j <= cur; ++j) {
				for(int k = 1; k <= v && k <= cur + 1; ++k) {
					long long cof = c[v - 1][k - 1];
					for(int l = 0; l <= j && l <= k; ++l) {
						dp[i + 1][j + v - l] = (dp[i + 1][j + v - l] + dp[i][j] * c[j][l] % P * c[cur + 1 - j][k - l] % P * cof % P) % P;
					}
				}
			}
			cur += v;
		}
		return dp[n][K];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {36, 36, 36, 36, 36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 2, 11, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 474640725; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 12133719; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 116; int Arg2 = 516440918; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
LISNumber ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
