#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

vector<int> G[maxn + 5];
int in[maxn + 5];
int out[maxn + 5];

namespace ac {
    struct data {
        int danger, fail; 
        int c[26];
    } t[maxn + 5];
    int root;
    int Pool = 0;
    int C = 26;
	int endpos[maxn + 5];
	void ins(string s, int id) {
        int now = root;
        for(int i = 0; i < (int)s.size(); ++i) {
            if(!t[now].c[s[i] - 'a']) {
                t[now].c[s[i] - 'a'] = ++Pool;
            }
            now = t[now].c[s[i] - 'a'];
        }
		endpos[id] = now;
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

vector<pair<int, int> > link[maxn + 5];

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

    void add(int p, T val) {
        for(int i = p; i < N; i += (i & -i)) {
            v[i] += val;
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p; i >= 1; i -= (i & -i)) {
            sum += v[i];
        }
        return sum;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int type;
		cin >> type;

		if (type == 1) {
			char c;
			cin >> c;
			link[0].emplace_back(i + 1, c - 'a');
		}

		if (type == 2) {
			int j;
			cin >> j;

			char c;
			cin >> c;

			link[j].emplace_back(i + 1, c - 'a');
		}
	}

	int m;
	cin >> m;

	vector<int> id(m);
	vector<vector<int> > ask(n + 1);
	for (int i = 0; i < m; ++i) {
		string s;
		int j;
		cin >> j >> s;
		ins(s, i);
		ask[j].emplace_back(i);
	}

	get_fail();

	for (int i = 1; i <= Pool; ++i) {
		G[t[i].fail].emplace_back(i);
	}

	int dfn = 0;
	function<void(int)> pre_dfs = [&] (int x) {
		in[x] = ++dfn;
		for (int y : G[x]) {
			pre_dfs(y);
		}
		out[x] = dfn;
	};

	pre_dfs(0);

	FenwickTree<int> fw(dfn + 1);
	vector<int> ans(m);
	function<void(int, int)> dfs = [&] (int x, int cur) {
		fw.add(in[cur], 1);
		for (int i : ask[x]) {
			ans[i] = fw.query(out[endpos[i]]) - fw.query(in[endpos[i]] - 1);	
		}
		for (auto [y, c] : link[x]) {
			dfs(y, t[cur].c[c]);
		}
		fw.add(in[cur], -1);
	};

	dfs(0, 0);

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
} 
