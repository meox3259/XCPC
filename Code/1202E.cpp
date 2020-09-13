#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

namespace ac {
    struct data {
        int danger, fail; 
        int c[26];
    } t[maxn];
    int root;
	int Pool = 0;
    void ins(string s) {
        int now = root;
		int l = s.size();
        for(int i = 0; i < l; ++i) {
            if(!t[now].c[s[i] - 'a']) {
				t[now].c[s[i] - 'a'] = ++Pool;
			}
            now = t[now].c[s[i] - 'a'];
        }
        t[now].danger += 1; 
    } 
    void get_fail() {
		queue<int> q;
        for(int i = 0; i < 26; ++i) {
			if(t[0].c[i]) {
				q.emplace(t[0].c[i]);
			}
		}
        while(!q.empty()) {
			int u = q.front();
			q.pop();
            t[u].danger += t[t[u].fail].danger;
            for(int i = 0; i < 26; ++i) {
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

	string st;
	cin >> st;

	int n;
	cin >> n;

	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for(auto o : s) {
		ins(o);
	}

	get_fail();

	vector<int> pre(st.size());
	int cur = root;
	for(int i = 0; i < st.size(); ++i) {
		int c = st[i] - 'a';
		cur = t[cur].c[c];
		pre[i] = t[cur].danger;
	}

	reverse(st.begin(), st.end());
	for(int i = 0; i < n; ++i) {
		reverse(s[i].begin(), s[i].end());
	}

	memset(t, 0, sizeof(t));
	Pool = 0;

	for(auto o : s) {
		ins(o);
	}

	get_fail();
	vector<int> suf(st.size());
	cur = root;

	for(int i = 0; i < st.size(); ++i) {
		int c = st[i] - 'a';
		cur = t[cur].c[c];
		suf[i] = t[cur].danger;
	}

	reverse(suf.begin(), suf.end());

	long long ans = 0;
	for(int i = 0; i < (int)st.size() - 1; ++i) {
		ans += 1LL * pre[i] * suf[i + 1];
	}

	cout << ans << '\n';

	return 0;
}
