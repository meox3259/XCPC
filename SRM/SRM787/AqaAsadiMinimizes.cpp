// BEGIN CUT HERE
// END CUT HERE
#line 4 "AqaAsadiMinimizes.cpp"
#include <bits/stdc++.h>

using namespace std;

class AqaAsadiMinimizes {
	public:
	double getMin(vector <int> P, int B0, int X, int Y, int N) {
		vector<long long> a(N);
		for(int i = 0; i < N; ++i) {
			if(i > P.size()) {
				a[i] = (a[i - 1] * X + Y) % 1000000007;
			}
			if(i == P.size()) {
				a[i] = B0;
			}
			if(i < P.size()) {
				a[i] = P[i];
			}
		}

		vector<pair<int, int> > b;
		for(int i = 0; i < N; ++i) {
			b.emplace_back(a[i], i);
		}

		sort(b.begin(), b.end());

		double ans = 2e9;

		for(int i = 0; i + 1 < N; ++i) {
			ans = min(ans, abs(b[i].first - b[i + 1].first) / (double)abs(b[i].second - b[i + 1].second));
		}

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {11, 0, 30, 20, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; double Arg5 = 3.0; verify_case(0, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {47, 1, 10, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; double Arg5 = 0.3333333333333333; verify_case(1, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {123456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 234567890; int Arg2 = 345678; int Arg3 = 456789; int Arg4 = 10; double Arg5 = 8333191.571428572; verify_case(2, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
AqaAsadiMinimizes ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
