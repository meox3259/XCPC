#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

void chkmin(int &x, int y) {
	if(x > y) {
		x = y;
	}
}

const int maxn = 100005;

namespace ac 
{
    struct data {
        int danger, fail; 
        int c[10];
    } t[maxn];
    int root;
	int Pool = 0;
    void ins(string s) {
        int now = root;
		int l = s.size();
        for(int i = 0; i < l; ++i) {
            if(!t[now].c[s[i] - '0']) {
				t[now].c[s[i] - '0'] = ++Pool;
			}
            now = t[now].c[s[i] - '0'];
        }
        t[now].danger = 1; 
    } 
    void get_fail() {
		queue<int> q;
        for(int i = 0; i < 10; ++i) {
			if(t[0].c[i]) {
				q.emplace(t[0].c[i]);
			}
		}
        while(!q.empty()) {
            int u = q.front();
			q.pop();
            t[u].danger |= t[t[u].fail].danger;
            for(int i = 0; i < 10; ++i) {
                int &v = t[u].c[i];
                if(!v) {
					v = t[t[u].fail].c[i];
				} else {
					t[v].fail = t[t[u].fail].c[i];
					q.emplace(v);
				}
            }
        }
    }
} using namespace ac;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int x;
	cin >> x;

	int n = s.size();

	string tmp = "";

	function<void(string, int)> dfs = [&] (string s, int sum) {
		if(sum == x) {
			bool ok = false;
			for(int i = 0; i < s.size(); ++i) {
				int S = 0;
				for(int j = i; j < s.size(); ++j) {
					S += s[j] - '0';
					if(x != S && x % S == 0) {
						ok = true;
					}
				}
			}
			if(!ok) {
				ins(s);
			}
			return;
		}
		for(int i = 1; i < 10; ++i) {
			if(sum + i <= x) {
				dfs(s + (char)('0' + i), sum + i);
			}
		}
	};

	dfs(tmp, 0);

	get_fail();

	vector<vector<int> > dp(n + 1, vector<int> (Pool + 1, inf));
	dp[0][0] = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= Pool; ++j) {
			dp[i + 1][j] = dp[i][j] + 1;	
		}
		for(int j = 0; j <= Pool; ++j) {
			int nxt = t[j].c[s[i] - '0'];
			if(!t[nxt].danger) {
				chkmin(dp[i + 1][nxt], dp[i][j]);
			}
		}
	}

	cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';

	return 0;
}
