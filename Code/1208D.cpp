#include <bits/stdc++.h>
using namespace std;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum += v[i - 1];
    }
    return sum;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  FenwickTree<long long> fw(N);
  for (int i = 0; i < N - 1; ++i) {
    fw.add(i + 1, i + 1);
  }
  vector<int> ans(N);
  for (int i = N - 1; i >= 0; --i) {
    int L = -1;
    int R = N;
    while (R - L > 1) {
      int mid = L + R >> 1;
      long long tot = fw.query(mid);
      if (tot <= S[i]) {
        L = mid;
      } else {
        R = mid;
      }
    }
    fw.add(L + 1, -L - 1);
    ans[i] = L;
  }
  for (int i = 0; i < N; ++i) {
    cout << ans[i] + 1 << " \n"[i == N - 1];
  }
  return 0;
}
