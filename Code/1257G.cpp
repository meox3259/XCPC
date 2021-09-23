#include <bits/stdc++.h>
using namespace std;
namespace poly { //method : use c = multiply(a, b)
  vector<int> rev = {0, 1};
  vector<int> Root = {0, 1};
  const int P = 998244353;
  const int G = 3;
  int power(int x, int t) {
    int ret = 1;
    for(; t; t >>= 1, x = 1LL * x * x % P) {
      if(t & 1) {
        ret = 1LL * ret * x % P;
      }
    }
    return ret;
  }
  void init(int n) {
    if(n <= Root.size()) {
      return;
    }
    rev.resize(n);
    for(int i = 0; i < n; ++i) {
      rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
    }
    if((int)Root.size() < n) {
      int k = __builtin_ctz(Root.size());
      Root.resize(n);
      while((1 << k) < n) {
        int z = power(G, (P - 1) >> (k + 1));
        for(int i = 1 << (k - 1); i < (1 << k); ++i) {
          Root[2 * i] = Root[i];
          Root[2 * i + 1] = 1LL * Root[i] * z % P;
        }
        k += 1;
      }
    }
  }
  void dft(vector<int> &a, int n) {
    init(n);
    int s = __builtin_ctz(rev.size() / n);
    for(int i = 0; i < n; ++i) {
      if(i < rev[i] >> s) {
        swap(a[i], a[rev[i] >> s]);
      }
    }
    for(int k = 1; k < n; k = k * 2) {
      for(int i = 0; i < n; i = i + k * 2) {
        for(int j = 0; j < k; ++j) {
          int t = 1LL * Root[j + k] * a[i + j + k] % P;
          a[i + j + k] = (a[i + j] - t + P) % P;
          a[i + j] = (a[i + j] + t) % P; 
        }
      }
    }
  }
  void idft(vector<int> &a, int n) {
    reverse(a.begin() + 1, a.end());
    dft(a, n);
    int inv = power(n, P - 2);
    for(int i = 0; i < n; ++i) {
      a[i] = 1LL * a[i] * inv % P;
    }
  }
  vector<int> multiply(vector<int> a, vector<int> b) { // return a * b size = sz(a) + sz(b)
    int s = a.size() + b.size() - 1;
    if(s <= 0) {
      return {};
    }
    int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0;
    int n = 1 << L;
    a.resize(n);
    dft(a, n);
    b.resize(n);
    dft(b, n);
    for(int i = 0; i < n; ++i) {
      a[i] = 1LL * a[i] * b[i] % P;
    }
    idft(a, n);
    a.resize(s);
    return a;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  map<int, int> cnt;
  for (int i : p) {
    cnt[i]++;
  }
  vector<int> a;
  for (auto o : cnt) {
    a.push_back(o.second);
  }
  sort(a.begin(), a.end());
  int m = a.size();
  vector<int> pre(m);
  pre[0] = a[0];
  for (int i = 0; i < m - 1; ++i) {
    pre[i + 1] = pre[i] + a[i + 1]; 
  }
  auto solve = [&] (auto &&f, int l, int r) -> vector<int> {
    if (l == r) {
      return vector<int> (a[l] + 1, 1);
    } 
    int mid = lower_bound(pre.begin() + l, pre.begin() + r - 1, (pre[r] + pre[l]) / 2) - pre.begin(); 
    return poly::multiply(f(f, l, mid), f(f, mid + 1, r));
  };
  a = solve(solve, 0, m - 1); 
  cout << a[pre.back() / 2] << '\n';
}
