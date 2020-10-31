#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

multiset<int> v[maxn * 2];

namespace ac {
    struct data {
        int danger, fail, link; 
        int c[26];
    } t[maxn];
    int root;
    int Pool = 0;
    int C = 26;
	int last[maxn];
	int mx[maxn];
	int link[maxn];
    int ins(string s) {
        int now = root;
        for(int i = 0; i < (int)s.size(); ++i) {
            if(!t[now].c[s[i] - 'a']) {
                t[now].c[s[i] - 'a'] = ++Pool;
            }
            now = t[now].c[s[i] - 'a'];
        }
        t[now].danger = 1; 
		mx[now] = 0;
		return now;
    } 
    void get_fail() {
        queue<int> q;
        for(int i = 0; i < C; ++i) {
            if(t[0].c[i]) {
                q.emplace(t[0].c[i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            t[u].danger |= t[t[u].fail].danger;
			link[u] = mx[t[u].fail] >= 0 ? t[u].fail : link[t[u].fail];
            for(int i = 0; i < C; ++i) {
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

	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	memset(last, -1, sizeof(last));
	memset(mx, -1, sizeof(mx));

	vector<int> endpos(n);
	for(int i = 0; i < n; ++i) {
		endpos[i] = ins(s[i]);
	}

	for(int i = 0; i < n; ++i) {
		last[i] = 0;
	}

	get_fail();

	for(int i = 0; i < n; ++i) {
		v[endpos[i]].emplace(0);
	}

	while(m--) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int i, x;
			cin >> i >> x;
			--i;

			v[endpos[i]].erase(v[endpos[i]].find(last[i]));
			last[i] = x;
			v[endpos[i]].emplace(x);
			mx[endpos[i]] = *v[endpos[i]].rbegin();
		}
		if(opt == 2) {
			string q;
			cin >> q;
			int cur = root;
			int ans = -1;
			for(int i = 0; i < q.size(); ++i) {
				int c = q[i];
				cur = t[cur].c[c - 'a'];
				for(int j = cur; j != root; j = link[j]) {
					ans = max(ans, mx[j]);
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
