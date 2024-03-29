// BEGIN CUT HERE
// END CUT HERE
#line 4 "TurnOnLamps.cpp"
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

class TurnOnLamps {
	public:
	int minimize(vector <int> roads, string initState, string isImportant) {
		int n = initState.size() + 1;
		vector<int> fa(n);
		vector<vector<int> > G(n);
		map<pair<int, int>, int> id;
		for(int i = 0; i < n - 1; ++i) {
			fa[i + 1] = roads[i];
			G[roads[i]].emplace_back(i + 1);
			id[minmax(roads[i], i + 1)] = i;
		}

		vector<vector<int> > dp(n, vector<int> (2, inf));

		function<void(int, int)> dfs = [&] (int u, int f) {
			dp[u][0] = 0;
			for(int v : G[u]) {
				if(v != f) {
					dfs(v, u);
					int x = dp[u][0];
					int y = dp[u][1];
					dp[u][0] = min(y + dp[v][1] - 1, x + min(dp[v][0], dp[v][1]));
					dp[u][1] = min(min(x, y) + dp[v][1], y + min(dp[v][0], dp[v][1]));
				}
			}

			if(u != 0 && isImportant[id[{ f, u }]] == '1' && initState[id[{ f, u }]] == '0') {
				dp[u][1] = min(dp[u][1], dp[u][0] + 1);
				dp[u][0] = inf;
			}

			if(u != 0 && isImportant[id[{ f, u }]] == '1' && initState[id[{ f, u }]] == '1') {
				dp[u][1] = inf;
			}
		};

		dfs(0, -1);

		return min(dp[0][0], dp[0][1]);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0001"; string Arg2 = "0111"; int Arg3 = 1; verify_case(0, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000"; string Arg2 = "0111"; int Arg3 = 2; verify_case(1, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "000100"; string Arg2 = "111111"; int Arg3 = 2; verify_case(2, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "100100"; string Arg2 = "011101"; int Arg3 = 2; verify_case(3, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,2,2,3,1,6,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010001110"; string Arg2 = "000110100"; int Arg3 = 1; verify_case(4, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000000000010000000000000010000010100000000000000"; string Arg2 = "1010111111111011011111000110111111111111111110111"; int Arg3 = 14; verify_case(5, Arg3, minimize(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
TurnOnLamps ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
