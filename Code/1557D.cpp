#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int> :: max() / 2;
class sgt {
  vector<pair<int, int>> mn;
  vector<pair<int, int>> tag;
 public:
  sgt() {}
  sgt(int n) : mn(n * 4, {0, -1}), tag(n * 4, {0, -1}) {}
  void pushdown(int x) {
    tag[x << 1] = min(tag[x << 1], tag[x]);
    tag[x << 1 | 1] = min(tag[x << 1 | 1], tag[x]);
    mn[x << 1] = min(mn[x << 1], tag[x]);
    mn[x << 1 | 1] = min(mn[x << 1 | 1], tag[x]);
  }
  void update(int l, int r, int x, int a, int b, pair<int, int> v) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      mn[x] = min(mn[x], v); 
      tag[x] = min(tag[x], v);
      return;
    }
    pushdown(x);
    int mid = l + r >> 1;
    update(l, mid, x << 1, a, b, v);
    update(mid + 1, r, x << 1 | 1, a, b, v);
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
  }
  pair<int, int> query(int l, int r, int x, int a, int b) {
    if (l > b || r < a) {
      return {0, -1};
    }
    if (l >= a && r <= b) {
      return mn[x];
    }
    pushdown(x);
    int mid = l + r >> 1;
    return min(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> row(n);
  vector<int> s;
  for (int j = 0; j < m; ++j) {
    int i, l, r;
    cin >> i >> l >> r;
    row[i - 1].emplace_back(l - 1, r - 1);
    s.push_back(l - 1);
    s.push_back(r - 1);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  int sz = s.size();
  auto id = [&] (int v) -> int {
    return lower_bound(s.begin(), s.end(), v) - s.begin();
  };
  vector<pair<int, int>> dp(n, {inf, -1});
  sgt sgt(sz);
  map<int, int> mp;
  vector<int> pre(n, -1);
  for (int i = 0; i < n; ++i) {
    for (auto [l, r] : row[i]) {
      dp[i] = min(dp[i], sgt.query(0, sz, 1, id(l), id(r)));
    }  
    pre[i] = dp[i].second;
    dp[i].first += i;
    dp[i].second = i;
    auto tmp = dp[i];
    tmp.first -= i + 1;
    for (auto [l, r] : row[i]) {
      sgt.update(0, sz, 1, id(l), id(r), tmp);
    }
  }
  int k = n;
  for (int i = 0; i < n; ++i) {
    k = min(k, dp[i].first + n - i - 1);
  }
  for (int i = 0; i < n; ++i) {
    if (k == dp[i].first + n - i - 1) {
      vector<bool> mark(n);
      vector<int> ans;
      int x = i;
      while (x != -1) {
        mark[x] = true;
        x = pre[x];
      }
      for (int j = 0; j < n; ++j) {
        if (!mark[j]) {
          ans.push_back(j); 
        }
      }
      assert(ans.size() == k);
      cout << k << '\n';
      for (int j = 0; j < k; ++j) {
        cout << ans[j] + 1 << " \n"[j == k - 1];
      }
      exit(0);
    }
  }
  cout << n - 1 << '\n';
  for (int i = 2; i <= n; ++i) {
    cout << i << " \n"[i == n];
  }
}
