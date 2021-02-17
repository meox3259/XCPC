#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max();

class SegmentTree {
    vector<int> mx;
    vector<int> tag;
    public:
    SegmentTree(int N) : mx(N * 4), tag(N * 4) {}

    void pushdown(int x) {
        mx[x << 1] += tag[x];
        mx[x << 1 | 1] += tag[x];
        tag[x << 1] += tag[x];
        tag[x << 1 | 1] += tag[x];
        tag[x] = 0;
    }

    void update(int l, int r, int x, int a, int b, int v) {
        if (l > b || r < a) {
            return;
        }
        if (l >= a && r <= b) {
            tag[x] += v;
            mx[x] += v;
            return;
        }
        pushdown(x);
        int mid = l + r >> 1;
        update(l, mid, x << 1, a, b, v);
        update(mid + 1, r, x << 1 | 1, a, b, v);
        mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
    }

    int Max() {
        return mx[1];
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			b[i] --;
		}

        vector<bool> vis(n * 2);
        for (int i : b) {
            vis[i] = true;
        }

        vector<bool> fi(n + 1);
        fi[0] = true;
        SegmentTree seg_1(n + n); 
        for (int i = 0, j = n + n - 1; i < n; ++i) {
            while (j >= 0 && vis[j]) {
                j --;
            }
            seg_1.update(0, n + n - 1, 1, j, n + n - 1, 1);
            seg_1.update(0, n + n - 1, 1, b[i], n + n - 1, -1);
            if (seg_1.Max() < 1) {
                fi[i + 1] = true;
            } 
            j --;
        }

        vector<bool> se(n + 1);
        se[0] = true;
        SegmentTree seg_2(n + n);
        for (int i = n - 1, j = 0; i >= 0; --i) {
            while (j < n + n && vis[j]) {
                j ++;
            }
            seg_2.update(0, n + n - 1, 1, 0, j, 1);
            seg_2.update(0, n + n - 1, 1, 0, b[i], -1);
            if (seg_2.Max() < 1) {
                se[i + 1] = true;
            }
            j ++;
        }

        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (fi[i] && se[i]) {
                ans ++;
            }
        }

		cout << ans << '\n';
	}

	return 0;
}
