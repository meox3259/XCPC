#include <bits/stdc++.h>
using namespace std;
class sgt {
 public:
  vector<long long> sum;
  vector<int> tag;
  vector<vector<int>> cnt;
  vector<vector<int>> add;
  sgt() {}
  sgt(int n) : sum(n * 4), tag(n * 4), cnt(n * 4, vector<int> (2)), add(n * 4, vector<int> (2)) {}
  void up(int x) {
    for (int i = 0; i < 2; ++i) {
      cnt[x][i] = cnt[x << 1][i] + cnt[x << 1 | 1][i];
    }
  }
  void down(int x) {
    if (tag[x]) {
      swap(cnt[x << 1][0], cnt[x << 1][1]);
      swap(add[x << 1][0], add[x << 1][1]);
      swap(cnt[x << 1 | 1][0], cnt[x << 1 | 1][1]);
      swap(add[x << 1 | 1][0], add[x << 1 | 1][1]);
      tag[x << 1] ^= 1;
      tag[x << 1 | 1] ^= 1;
      tag[x] = 0;
    }
    for (int i = 0; i < 2; ++i) {
      if (add[x][i]) {
        sum[x << 1] += 1ll * cnt[x << 1][i] * add[x][i];
        sum[x << 1 | 1] += 1ll * cnt[x << 1 | 1][i] * add[x][i];
        add[x << 1][i] += add[x][i];
        add[x << 1 | 1][i] += add[x][i];
        add[x][i] = 0;
      }
    }
  }
  void build(int l, int r, int x) {
    cnt[x][0] = r - l + 1;
    if (l == r) {
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, x << 1);
    build(mid + 1, r, x << 1 | 1);
    up(x);
  }
  void flip(int l, int r, int x, int a, int b) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      tag[x] ^= 1;
      swap(cnt[x][0], cnt[x][1]);
      swap(add[x][0], add[x][1]);
      return;
    }
    down(x);
    int mid = l + r >> 1;
    flip(l, mid, x << 1, a, b);
    flip(mid + 1, r, x << 1 | 1, a, b);
    up(x);
  }
  long long query(int l, int r, int x, int a, int b) {
    if (l > b || r < a) {
      return 0;
    }
    if (l >= a && r <= b) {
      return sum[x];
    }
    down(x);
    int mid = l + r >> 1;
    return query(l, mid, x << 1, a, b) + query(mid + 1, r, x << 1 | 1, a, b);
  }
};  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] --;
  }
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> ask(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    l --;
    r --;
    ask[r].emplace_back(l, i);
  }
  sgt sgt(n);
  sgt.build(0, n - 1, 1);
  vector<int> last(n, -1);
  vector<long long> ans(q);
  for (int i = 0; i < n; ++i) {
    sgt.flip(0, n - 1, 1, last[a[i]] + 1, i);
    last[a[i]] = i;
    sgt.add[1][1] = 1;
    sgt.sum[1] += sgt.cnt[1][1];
    for (auto [j, id] : ask[i]) {
      ans[id] = sgt.query(0, n - 1, 1, j, i); 
    } 
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}
