// BEGIN CUT HERE
// END CUT HERE
#line 4 "ShoutterDiv1.cpp"
#include <bits/stdc++.h>

using namespace std;

class ShoutterDiv1 {
	public:
	int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
		string x1000 = "";
		string x100 = "";
		string x10 = "";
		string x1 = "";
		for(int i = 0; i < s1000.size(); ++i) {
			x1000 += s1000[i];
			x100 += s100[i];
			x10 += s10[i];
			x1 += s1[i];
		}

		string y1000 = "";
		string y100 = "";
		string y10 = "";
		string y1 = "";
		for(int i = 0; i < s1000.size(); ++i) {
			y1000 += t1000[i];
			y100 += t100[i];
			y10 += t10[i];
			y1 += t1[i];
		}

		vector<pair<int, int> > s;
		int n = x1000.size();
		for(int i = 0; i < n; ++i) {
			s.emplace_back((x1000[i] - '0') * 1000 + (x100[i] - '0') * 100 + (x10[i] - '0') * 10 + x1[i] - '0',
						   (y1000[i] - '0') * 1000 + (y100[i] - '0') * 100 + (y10[i] - '0') * 10 + y1[i] - '0');
		}

		int ans = 0;
		vector<int> dp(n);
		for(int p = 0; p < n; ++p) {
			vector<pair<int, int> > l;
			vector<pair<int, int> > r;
			for(int i = 0; i < n; ++i) {
				if(!(s[i].second < s[p].first || s[i].first > s[p].second)) {
					l.emplace_back(s[i]);
					r.emplace_back(s[i]);
				} else if(s[i].first > s[p].second) {
					r.push_back(s[i]);
				} else if(s[i].second < s[p].first) {
					l.push_back(s[i]);
				}
			}

			sort(l.begin(), l.end(), [&] (pair<int, int> a, pair<int, int> b) {
				return a.second < b.second;
			});
			int cur = s[p].first;
			int delta = 0;
			int tmp = 1000000000;
			int mn = s[p].first;
			for(int i = (int)l.size() - 1; i >= 0; --i) {
				mn = min(mn, l[i].first);
				if(l[i].second >= cur) {
					tmp = min(tmp, l[i].first);
				} else {
					if(l[i].second < tmp) {
						return -1;
					}
					delta += 1;
					cur = tmp;
					tmp = min(tmp, l[i].first);
				}
			}

			sort(r.begin(), r.end(), [&] (pair<int, int> a, pair<int, int> b) {
				return a.first < b.first;
			});

			tmp = -1000000000;
			cur = s[p].second;
			int mx = s[p].second;
			for(int i = 0; i < r.size(); ++i) {
				mx = max(mx, r[i].second);
				if(r[i].first <= cur) {
					tmp = max(tmp, r[i].second);
				} else {
					if(r[i].first > tmp) {
						return -1;
					}
					delta += 1;
					cur = tmp;
					tmp = max(tmp, r[i].second);
				}
			}

			dp[p] = delta; 
		} 

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(!(s[i].second < s[j].first || s[i].first > s[j].second)) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}

		for(int i : dp) {
			ans += i;
		}

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"22", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"11", "1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"21", "4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"22", "2"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00", "0"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"11", "1"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"43", "6"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 2; verify_case(0, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { string Arr0[] = {"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"13"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"00"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"00"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"24"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = -1; verify_case(1, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { string Arr0[] = {"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1234"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"0000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"0000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"0000"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"2345"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 6; verify_case(2, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { string Arr0[] = {"0000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000000000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"7626463146"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"0000000000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"0000000000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"0000000000"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"9927686479"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 18; verify_case(3, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { string Arr0[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"50353624751857130208544645495168271486083954769538"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"85748487990028258641117783760944852941545064635928"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"61465744851859252308555855596388482696094965779649"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"37620749792666153778227385275518278477865684777411"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 333; verify_case(4, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
ShoutterDiv1 ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
