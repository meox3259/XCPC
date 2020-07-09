// BEGIN CUT HERE
// END CUT HERE
#line 4 "GridSpiral.cpp"
#include <bits/stdc++.h>

using namespace std;

class GridSpiral {
	public:
	long long findCell(int D) {
		if(D % 2 == 0) {
			return -1;
		}		
		if(D == 1 || D == 3 || D == 5 || D == 7) {
			return 0;
		}
		if(D == 9) {
			return 1;
		}
		if(D == 11) {
			return 2;
		} 
		long long x = (D - 3) / 2;
		long long r = (x - 1) / 4 * 2;
		long long s = r * r - 1;
		long long rem = (x - 1) % 4;
		if(rem == 0) {
			return s + 1;
		} else {
			return s + rem * (r + 1);
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; long long Arg1 = 0LL; verify_case(0, Arg1, findCell(Arg0)); }
	void test_case_1() { int Arg0 = 11; long long Arg1 = 2LL; verify_case(1, Arg1, findCell(Arg0)); }
	void test_case_2() { int Arg0 = 47; long long Arg1 = 110LL; verify_case(2, Arg1, findCell(Arg0)); }
	void test_case_3() { int Arg0 = 100; long long Arg1 = -1LL; verify_case(3, Arg1, findCell(Arg0)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
GridSpiral ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
