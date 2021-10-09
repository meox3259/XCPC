#include <bits/stdc++.h>
using namespace std;
class dsu {
 private:
  vector<int> dat;
  int components_;
 public:
  dsu() {}
  explicit dsu(int n) : dat(n, -1), components_(n) {}
  int size() {
    return dat.size();
  }
  int root(int x) {
    assert(0 <= x), assert(x < size());
    return dat[x] < 0 ? x : dat[x] = root(dat[x]);
  }
  pair<int, int> unite(int x, int y) {
    assert(0 <= x), assert(x < size());
    assert(0 <= y), assert(y < size());
    x = root(x), y = root(y);
    if (x == y) {
      return { x, -1 };
    }
    components_ --;
    if (-dat[x] < -dat[y]) {
      swap(x, y);
    }
    dat[x] += dat[y];
    dat[y] = x;
    return { x, y };
  }
  bool same(int x, int y) {
    assert(0 <= x), assert(x < size());
    assert(0 <= y), assert(y < size());
    return root(x) == root(y);
  }
  int size(int x) {
    assert(0 <= x), assert(x < size());
    return -dat[root(x)];
  }
  int components() {
    return components_;
  }
  int operator [] (int x) {
    return root(x);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> val(n + m);
  for (int i = 0; i < n; ++i) {
    cin >> val[i];
  }
  vector<vector<int>> f(200001);
  for (int i = 1; i <= 200000; ++i) {
    for (int j = i; j <= 200000; j += i) {
      int k = i ^ j; 
      if (k <= 200000 && __gcd(j, k) == i) {
        f[j].push_back(k); 
        f[k].push_back(j);
      }
    }
  }
  for (int i = 1; i <= 200000; ++i) {
    sort(f[i].begin(), f[i].end());
    f[i].erase(unique(f[i].begin(), f[i].end()), f[i].end());
  }
  dsu dsu(n + m);
  vector<map<int, int>> mp(n + m);
  for (int i = 0; i < n; ++i) {
    mp[i][val[i]]++;
  }
  long long ans = 0;
  while (m--) {
    int opt, x, y;
    cin >> opt >> x >> y;
    x--;
    if (opt == 1) {
      val[x] = y;
      mp[dsu[x]][y]++;
    }
    if (opt == 2) {
      y--;
      if (!dsu.same(x, y)) {
        tie(y, x) = dsu.unite(x, y);
        for (auto o : mp[x]) {
          int i = o.first;
          for (int j : f[i]) {
            if (mp[y].find(j) != mp[y].end()) {
              ans += 1ll * mp[y][j] * o.second; 
            }
          }  
        }
        for (auto o : mp[x]) {
          mp[y][o.first] += o.second;
        }
        mp[x].clear();
      }
    }
    if (opt == 3) {
      mp[dsu[x]][val[x]]--;
      for (int i : f[val[x]]) {
        if (mp[dsu[x]].find(i) != mp[dsu[x]].end()) {
          ans -= mp[dsu[x]][i];
        }
      } 
      for (int i : f[y]) {
        if (mp[dsu[x]].find(i) != mp[dsu[x]].end()) {
          ans += mp[dsu[x]][i];
        }
      }
      mp[dsu[x]][y]++;
      val[x] = y;
    }
    cout << ans << '\n';
  }
}
