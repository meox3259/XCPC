// BEGIN CUT HERE
// END CUT HERE
#line 4 "TreeUnion.cpp"
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

class TreeUnion {
	public:
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		string s = "";
		for(auto o : tree1) {
			s += o;
		}

		string t = "";
		for(auto o : tree2) {
			t += o;
		}

		vector<int> a;
		int last = -1;
		s = s + ' ';
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == ' ') {
				int x = 0;
				for(int j = last + 1; j < i; ++j) {
					x = x * 10 + s[j] - '0';
				}
				last = i;
				a.emplace_back(x);
			}
		}

		vector<int> b;
		last = -1;
		t = t + ' ';
		for(int i = 0; i < t.size(); ++i) {
			if(t[i] == ' ') {
				int x = 0;
				for(int j = last + 1; j < i; ++j) {
					x = x * 10 + t[j] - '0';
				}
				last = i;
				b.emplace_back(x);
			}
		}

		int n = a.size() + 1;

		vector<vector<int> > d1(n, vector<int> (n, inf));
		for(int i = 0; i < n; ++i) {
			d1[i][i] = 0;
		}

		for(int i = 0; i < n - 1; ++i) {
			d1[i + 1][a[i]] = 1;
			d1[a[i]][i + 1] = 1;
		}

		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
				}
			}
		}

		vector<vector<int> > d2(n, vector<int> (n, inf));
		for(int i = 0; i < n; ++i) {
			d2[i][i] = 0;
		}

		for(int i = 0; i < n - 1; ++i) {
			d2[i + 1][b[i]] = 1;
			d2[b[i]][i + 1] = 1;
		}

		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
				}
			}
		}

		vector<vector<int> > d(n, vector<int> (n));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				d[i][d2[i][j]] += 1;
			}
		}

		double ans = .0;
		for(int x = 0; x < n; ++x) {
			for(int y = 0; y < n; ++y) {
				if(x != y) {
					for(int z = 0; z < n; ++z) {
						int dis = K - d1[x][y] - 2;
						if(dis > 0) {
							double v = d[z][dis];	
							ans += v;
						}
					}
				}
			}
		}

		ans = ans / 2.0;
		ans = ans / (double)n;
		ans = ans / (double)(n - 1);

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 1.0; verify_case(0, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 1.3333333333333333; verify_case(1, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; double Arg3 = 0.3333333333333333; verify_case(2, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0 ", "1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 ", "1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 4.0; verify_case(3, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 13.314285714285713; verify_case(4, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
TreeUnion ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
