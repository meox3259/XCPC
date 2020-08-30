#include <bits/stdc++.h>

using namespace std;

const int N = 800005;
const int inf = 1000000000;

namespace SegmentTree {
	int s[N];
	int mn[N];
	bool tag[N];

	void pushdown(int x, int l, int r) {
		int mid = l + r >> 1;
		if(tag[x]) {
			tag[x << 1] = true;
			tag[x << 1 | 1] = true;
			s[x << 1] = s[x];
			s[x << 1 | 1] = s[x] + mid - l + 1;
			mn[x << 1] = s[x << 1];
			mn[x << 1 | 1] = s[x << 1 | 1];
			tag[x] = false;
		}
	}

	void update(int l, int r, int x, int a, int b, int S) {
		if(l > b || r < a) {
			return;
		}
		if(l >= a && r <= b) {
			tag[x] = true;
			s[x] = S + l - a;
			mn[x] = S + l - a;
			return;
		}
		pushdown(x, l, r);
		int mid = l + r >> 1;
		update(l, mid, x << 1, a, b, S);
		update(mid + 1, r, x << 1 | 1, a, b, S);
		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}

	int query(int l, int r, int x, int a, int b) {
		if(l > b || r < a) {
			return inf;
		}	
		if(l >= a && r <= b) {
			return mn[x];	
		}
		pushdown(x, l, r);
		int mid = l + r >> 1;
		return min(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
	}
} using namespace SegmentTree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	vector<int> a(h);
	vector<int> b(h);
	for(int i = 0; i < h; ++i) {
		cin >> a[i] >> b[i];
		a[i] -= 1;
		b[i] -= 1;
	}

	int x = 0;
	int y = 0;
	int ans = 0;

	for(int i = 0; i < h; ++i) {
		if(a[i] > 0) {
			int S = query(0, w - 1, 1, a[i] - 1, a[i] - 1);
			update(0, w - 1, 1, a[i], b[i], S + 1);
		} else {
			update(0, w - 1, 1, a[i], b[i], inf);
		}
		int ans = mn[1];
		if(ans >= inf) {
			cout << -1 << '\n';
		} else {
			cout << ans + i + 1<< '\n';
		}
	}

	return 0;
}
