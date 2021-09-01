#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] += val;
      v[i - 1] %= mod;
    }
  }
  T query(int p) {
    T sum = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum += v[i - 1];
      sum %= mod;
    }
    return sum;
  }
  T range(int L, int R) {
    return (query(R) - query(L - 1) + mod) % mod;
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] --;
  }
  vector<int> lst(n, -1);
  vector<int> mp(n, -1);
  for (int i = 0; i < n; ++i) {
    lst[i] = mp[a[i]];
    mp[a[i]] = i;
  }
  vector<long long> dp(n);
  FenwickTree<long long> fw(n);
  for (int i = 0; i < n; ++i) {
    dp[i] += fw.range(max(0, lst[i]), i);
    if (lst[i] == -1) {
      dp[i] ++;
      dp[i] %= mod;
    } else {
      fw.add(lst[i], -dp[lst[i]]);
    }
    fw.add(i, dp[i]);
  }
  cout << fw.range(0, n - 1) << '\n';
}
