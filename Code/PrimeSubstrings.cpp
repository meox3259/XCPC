// BEGIN CUT HERE
// END CUT HERE
#line 4 "PrimeSubstrings.cpp"
#include <bits/stdc++.h>

using namespace std;

const string digit[] = { "7", "97", "991", "9377", "99371", "999331", "13133399" }; 

class PrimeSubstrings {
	public:
	string construct(int N, int L) {
		string ans = "";
		if(L < 7) {
			for(int i = 0; i < N; ++i) {
				ans += digit[L - 1][i % L];
			}
			return ans;
		}
		for(int i = 0; i < N; ++i) {
			ans += digit[6][i % 8];
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; string Arg2 = "5317"; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; string Arg2 = "1301779"; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "13079"; verify_case(2, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
PrimeSubstrings ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
