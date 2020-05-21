// BEGIN CUT HERE
// END CUT HERE
#line 4 "History.cpp"
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

class History {
	public:
	string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
		int n = dynasties.size();
		vector<vector<int> > year(n);
		for(int i = 0; i < n; ++i) {
			string s = dynasties[i];
			s = s + ' ';
			int last = -1;
			for(int j = 0; j < s.size(); ++j) {
				if(s[j] == ' ') {
					int x = 0;
					for(int k = last + 1; k < j; ++k) {
						x = x * 10 + s[k] - '0';
					}
					year[i].emplace_back(x);
					last = j;
				}
			}
		}

		vector<vector<int> > low(n, vector<int> (n, -inf));
		vector<vector<int> > high(n, vector<int> (n, inf));

		string t = "";
		for(int i = 0; i < battles.size(); ++i) {
			t += battles[i];
		}
		t += ' ';

		int last = -1;
		for(int i = 0; i < t.size(); ++i) {
			if(t[i] == ' ') {
				string s = "";
				for(int j = last + 1; j < i; ++j) {
					s += t[j];
				}

				last = i;

				int a = s[0] - 'A';
				int b = 0;
				int p = -1;
				for(int j = 1; j < s.size(); ++j) {
					if('A' <= s[j] && s[j] <= 'Z') {
						b = s[j] - 'A';
						p = j;
						break;
					}
				}
				int x = 0;
				for(int j = 1; j < s.size(); ++j) {
					if('0' <= s[j] && s[j] <= '9') {
						x = x * 10 + s[j] - '0';
					} else {
						break;
					}
				}
				int y = 0;
				for(int j = p; j < s.size(); ++j) {
					if('0' <= s[j] && s[j] <= '9') {
						y = y * 10 + s[j] - '0';
					} 	
				}
				low[a][b] = max(low[a][b], year[b][y] - year[a][x + 1] + 1);
				low[b][a] = max(low[b][a], year[a][x] - year[b][y + 1] + 1);
				high[a][b] = min(high[a][b], year[b][y + 1] - year[a][x] - 1);
				high[b][a] = min(high[b][a], year[a][x + 1] - year[b][y] - 1);
			}
		}

		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					low[i][j] = max(low[i][j], low[i][k] + low[k][j]);
					high[i][j] = min(high[i][j], high[i][k] + high[k][j]);
				}
			}
		} 

		string ans(queries.size(), 'N');

		for(int i = 0; i < queries.size(); ++i) {
			string s = queries[i];
			int a = s[0] - 'A';
			int b = 0;
			int p = -1;
			for(int j = 1; j < s.size(); ++j) {
				if('A' <= s[j] && s[j] <= 'Z') {
					b = s[j] - 'A';
					p = j;
					break;
				}
			}
			int x = 0;
			for(int j = 1; j < s.size(); ++j) {
				if('0' <= s[j] && s[j] <= '9') {
					x = x * 10 + s[j] - '0';
				} else {
					break;
				}
			}
			int y = 0;
			for(int j = p; j < s.size(); ++j) {
				if('0' <= s[j] && s[j] <= '9') {
					y = y * 10 + s[j] - '0';
				} 
			}
			int l = year[b][y] - year[a][x + 1] + 1;
			int r = year[b][y + 1] - year[a][x] - 1;

			if(l > high[a][b] || r < low[a][b]) {
				ans[i] = 'N';
			} else {
				ans[i] = 'Y';
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
	void test_case_0() { string Arr0[] = {"1 2 4",
 "1 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A1-B0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYY"; verify_case(0, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B1-C0 A0-B0 A2-C1 B1-C1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYYYNN"; verify_case(1, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 4 5",
 "10 13 17"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B0 A0-B0 B0-A0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYY"; verify_case(2, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 5 6",
 "1 2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0",
 "-B0 A",
 "1-B1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYY"; verify_case(3, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYNNYNNNY"; verify_case(4, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
History ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
