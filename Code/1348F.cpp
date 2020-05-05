#include <bits/stdc++.h>

using namespace std;

const int N = 200000;

namespace io {
    const int Maxlen = N * 50;
    char buf[Maxlen], *C = buf;
    int Len;

    inline void read_in() {
        Len = fread(C, 1, Maxlen, stdin);
        buf[Len] = '\0';
    }

	template <typename T>
    inline void fread(T &x) {
        x = 0;
        T f = 1;

        while (!isdigit(*C)) { 
			if(*C == '-') {
				f = -1; 
			}
			++C; 
		}

        while (isdigit(*C)) {
			x = (x << 1) + (x << 3) + *C - '0';
			++C;
		}

        if(f == -1) {
			x = -x;
    	}
	}

	template <typename T>
    inline void read(T &x) {
        x = 0;
        T f = 1; 
		char c = getchar();

        while(!isdigit(c)) { 
			if(c == '-') {
				f = -1;
			}
			c= getchar(); 
		}

        while(isdigit(c)) { 
			x = (x << 1ll) + (x << 3ll) + c - '0'; 
			c = getchar(); 
		}

		if(f == -1) {
			x = -x;
		}
    } 
}

template <class T>
class SegmentTree {
	int N;
	vector<T> tag;
	vector<T> mn;
	vector<unordered_map<T, bool> > s; 

	public:
	SegmentTree(int N) : N(N), tag(N * 4 + 5), mn(N * 4 + 5), s(N * 4 + 5) {}

	void pushdown(int x) {
		if(tag[x] != 0) {
			tag[x << 1] += tag[x];
			tag[x << 1 | 1] += tag[x];
			mn[x << 1] += tag[x];
			mn[x << 1 | 1] += tag[x];
			tag[x] = 0;
		}
	}

	void update(int l, int r, int x, int a, int b, int v) {
		if(l > b || r < a) {
			return;
		}
		if(l >= a && r <= b) {
			tag[x] += v;
			mn[x] += v;
			return;
		}
		pushdown(x);
		int mid = l + r >> 1;
		update(l, mid, x << 1, a, b, v);
		update(mid + 1, r, x << 1 | 1, a, b, v);
		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}

	void add(int l, int r, int x, int a, int b, int i) {
		if(l > b || r < a) {
			return;
		}
		if(l >= a && r <= b) {
			s[x][i] = true;
			return;
		}
		int mid = l + r >> 1;
		add(l, mid, x << 1, a, b, i);
		add(mid + 1, r, x << 1 | 1, a, b, i);
	}

	void del(int l, int r, int x, int a, int b, int i) {
		if(l > b || r < a) {
			return;
		}
		if(l >= a && r <= b) {
			s[x].erase(i);
			return;
		}
		int mid = l + r >> 1;
		del(l, mid, x << 1, a, b, i);
		del(mid + 1, r, x << 1 | 1, a, b, i);
	}

	int get_pos(int l, int r, int x) {
		if(l == r) {
			return l;
		}
		pushdown(x);
		int mid = l + r >> 1;
		if(mn[x << 1] < mn[x << 1 | 1]) {
			return get_pos(l, mid, x << 1);
		} else {
			return get_pos(mid + 1, r, x << 1 | 1);
		}
	}

	int get_ans(int l, int r, int x, int p) {
		if(!s[x].empty()) {
			return s[x].begin() -> first;
		}
		if(l == r) {
			return -1;
		}
		int mid = l + r >> 1;
		if(p <= mid) {
			return get_ans(l, mid, x << 1, p);
		} else {
			return get_ans(mid + 1, r, x << 1 | 1, p);
		}
	}

	int get_mn() {
		return mn[1];
	}
};

int main() {
	io::read_in();
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int n;
	io::fread(n);

	SegmentTree<int> T(n);

	vector<pair<int, int> > seg;

	for(int i = 0; i < n; ++i) {
		int l, r;
		io::fread(l); io::fread(r);
		--l; --r;
		seg.emplace_back(l, r);
		T.update(0, n - 1, 1, l, r, 1);
		T.add(0, n - 1, 1, l, r, i);
	}

	bool ok = true;

	vector<int> ans(n);

	for(int i = 0; i < n; ++i) {
		int p = T.get_pos(0, n - 1, 1);
		if(T.get_mn() > 1) {
			ok = false;
			break;
		}
		int x = T.get_ans(0, n - 1, 1, p);
		ans[x] = p;
		assert(x >= 0 && p >= 0);
		T.del(0, n - 1, 1, seg[x].first, seg[x].second, x);
		T.update(0, n - 1, 1, seg[x].first, seg[x].second, -1);
		T.update(0, n - 1, 1, p, p, n + 1);
	}

	if(ok) {
		cout << "YES" << '\n';
		for(int i : ans) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	} else {
		cout << "NO" << '\n';
		set<pair<int, int> > s;
		vector<vector<pair<int, int> > > G(n);

		for(int i = 0; i < n; ++i) {
			G[seg[i].first].emplace_back(seg[i].second, i);
		}
	
		vector<int> ans(n);
		vector<int> nxt(n, -1);
		vector<int> mir(n);

		for(int i = 0; i < n; ++i) {
			for(auto j : G[i]) {
				s.emplace(j);
			}
			ans[s.begin() -> second] = i;
			if(s.size() > 1) {
				nxt[i] = next(s.begin()) -> second;
			}
			s.erase(s.begin());
		}

		for(int i = 0; i < n; ++i) {
			mir[ans[i]] = i;
		}

		for(int i : ans) {
			cout << i + 1 << ' ';
		}
		cout << '\n';

		for(int i = 0; i < n; ++i) {
			if(nxt[i] != -1 && ans[nxt[i]] <= seg[mir[i]].second) {
				swap(ans[mir[i]], ans[nxt[i]]);
				break;
			}
		}
	
		for(int i : ans) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
