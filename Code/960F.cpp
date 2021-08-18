#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int> :: max() / 2;
class sgt {
  vector<int> lc;
  vector<int> rc;
  vector<int> mx;
  int pool;
 public:
  sgt() {}
  sgt(int _n) : lc(_n * 60), rc(_n * 60), mx(_n * 60) { pool = 0; }
  void update(int l, int r, int &x, int p, int v) {
    if (x == 0) {
      x = ++pool;
    }
    mx[x] = max(mx[x], v);
    if (l == r) {
      return;
    } 
    int mid = l + r >> 1;
    if (p <= mid) {
      update(l, mid, lc[x], p, v);
    } else {
      update(mid + 1, r, rc[x], p, v);
    }
  }
  int query(int l, int r, int x, int a, int b) {
    if (x == 0) {
      return 0;
    }
    if (l > b || r < a) {
      return -inf;
    } 
    if (l >= a && r <= b) {
      return mx[x];
    }
    int mid = l + r >> 1;
    return max(query(l, mid, lc[x], a, b), query(mid + 1, r, rc[x], a, b));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> root(n);
  sgt sgt(100001);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    a --;
    b --;
    int last = sgt.query(0, 100000, root[a], 0, w - 1) + 1;
    sgt.update(0, 100000, root[b], w, last);
    ans = max(ans, last);
  }
  cout << ans << '\n';
}
