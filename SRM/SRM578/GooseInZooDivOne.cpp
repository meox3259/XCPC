// BEGIN CUT HERE
// END CUT HERE
#line 4 "GooseInZooDivOne.cpp"
#include <bits/stdc++.h>

using namespace std;

class dsu {
	vector<int> par;

	public:
	dsu(int N) : par(N) {
		iota(par.begin(), par.end(), 0);
	} 

	int find(int x) {
		return x == par[x] ? x : par[x] = find(par[x]);
	}

	bool isroot(int x) {
		return x == find(x);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void Union(int x, int y) {
		if(same(x, y)) {
			return;
		}

		x = find(x);
		y = find(y);
		par[x] = y;
	}
};

const int P = 1000000007;

class GooseInZooDivOne {
	public:
	int count(vector <string> field, int dist) {
		int n = field.size();
		int m = field[0].size();
		dsu dsu(n * m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(field[i][j] == 'v') {
					for(int x = -dist; x <= dist; ++x) {
						for(int y = -dist; y <= dist; ++y) {
							if(abs(x) + abs(y) <= dist && 0 <= i + x && i + x < n && 0 <= j + y && j + y < m && field[i + x][j + y] == 'v') {
								dsu.Union(i * m + j, (i + x) * m + j + y);
							}
						}
					}
				}
			}
		}		

		vector<int> cnt(n * m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(field[i][j] == 'v') {
					cnt[dsu.find(i * m + j)] += 1; 
				}
			}
		}

		vector<int> goose;
		for(int i : cnt) {
			if(i > 0) {
				goose.emplace_back(i);
			}
		}

		int k = goose.size();
		vector<vector<int> > dp(k + 1, vector<int> (n * m + 1));
		dp[0][0] = 1;
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j <= n * m; ++j) {
				dp[i + 1][j] = dp[i][j];
			}
			for(int j = 0; j + goose[i] <= n * m; ++j) {
				dp[i + 1][j + goose[i]] = (dp[i + 1][j + goose[i]] + dp[i][j]) % P;
			}
		}

		int ans = 0;
		for(int i = 2; i <= n * m; i += 2) {
			ans = (ans + dp[k][i]) % P;
		}

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 898961330; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
GooseInZooDivOne ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
