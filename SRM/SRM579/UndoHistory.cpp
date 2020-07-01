// BEGIN CUT HERE
// END CUT HERE
#line 4 "UndoHistory.cpp"
#include <bits/stdc++.h>

using namespace std;

class UndoHistory {
	public:
	int minPresses(vector <string> lines) {
		int n = lines.size();
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			string s = lines[i];
			int cur = 0;
			if(i != 0) {
				cur += 2;
			}
			cur += s.size() + 1;
			for(int j = i - 1; j >= 0; --j) {
				int tmp = -1;
				string t = lines[j];
				for(int k = 1; k <= min((int)s.size(), (int)t.size()); ++k) {
					if(s.substr(0, k) == t.substr(0, k)) {
						tmp = max(tmp, k);
					}
				}
				tmp = (int)s.size() - tmp;
				tmp += 2;
				tmp += 1;
				cur = min(cur, tmp);
			}
			if(i > 0) {
				string t = lines[i - 1];
				if(t.size() <= s.size() && t == s.substr(0, (int)t.size())) {
					cur = min(cur, (int)s.size() - (int)t.size() + 1);
				}
			}
			ans += cur;
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tomorrow", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, minPresses(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minPresses(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "ab", "abac", "abacus" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minPresses(Arg0)); }
	void test_case_3() { string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(3, Arg1, minPresses(Arg0)); }
	void test_case_4() { string Arr0[] = {"ba","a","a","b","ba"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minPresses(Arg0)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
UndoHistory ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
