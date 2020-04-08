#include <bits/stdc++.h>

using namespace std;

class seg {
	vector<int> t;
	vector<int> tag;

	public:
	seg(int n) {
		t.resize(4 * n + 5);
		tag.resize(4 * n + 5);
	}

	void pushdown(int x) {
		tag[x << 1] += tag[x];
		tag[x << 1 | 1] += tag[x];
		
		t[x << 1] += tag[x];
		t[x << 1 | 1] += tag[x];

		tag[x] = 0;
	}

	void update(int l, int r, int x, int a, int b, int v) {
		if(l > b || r < a) {
			return;
		}

		if(l >= a && r <= b) {
			tag[x] += v;
			t[x] += v;
			return;
		}

		pushdown(x);

		int mid = l + r >> 1;

		update(l, mid, x << 1, a, b, v);
		update(mid + 1, r, x << 1 | 1, a, b, v);

		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}

	int get_max() {
		return t[1];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p;
	p.resize(n);

	for(int &i : p) {
		cin >> i;
	}

	vector<int> pos;
	pos.resize(n);

	for(int i = 0; i < n; ++i) {
		pos[p[i] - 1] = i;
	}

	int ans = n - 1;

	seg seg(n);

	seg.update(0, n - 1, 1, 0, pos[n - 1], 1);

	for(int i = 0; i < n; ++i) {
		int q;
		cin >> q;

		while(seg.get_max() <= 0) {
			seg.update(0, n - 1, 1, 0, pos[--ans], 1);
		}

		seg.update(0, n - 1, 1, 0, q - 1, -1);

		cout << ans + 1 << " \n"[i == n - 1];
	}

	return 0;
}
