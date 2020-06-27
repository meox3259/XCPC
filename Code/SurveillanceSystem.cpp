// BEGIN CUT HERE
// END CUT HERE
#line 4 "SurveillanceSystem.cpp"
#include <bits/stdc++.h>

using namespace std;

class SurveillanceSystem {
	public:
	string getContainerInfo(string containers, vector <int> reports, int L) {
		int n = containers.size();
		string ans(n, 'X');
		for(int i = 0; i < n; ++i) {
			int l = max(0, i - L + 1);
			int r = i;
			vector<int> a(n + 1);
			vector<int> b(n + 1);
			for(int j = 0; j + L - 1 < n; ++j) {
				int c = 0;
				for(int k = 0; k < L; ++k) {
					c += (containers[k + j] == 'X');
				}
				if(j < l || j > r) {
					a[c] += 1;
				} else {
					b[c] += 1;
				}
			}
			bool ok1 = true;
			bool ok2 = false;
			for(int j : reports) {
				a[j] -= 1;
			}
			for(int j : reports) {
				if(b[j] > 0) {
					ok2 = true;
				}
			}
			if(*min_element(a.begin(), a.end()) < 0) {
				ok1 = false;
			}
			if(!ok1) {
				ans[i] = '+';
			} else {
				if(!ok2) {
					ans[i] = '-';
				} else {
					ans[i] = '?';
				}
			}
		}
		
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
SurveillanceSystem ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
