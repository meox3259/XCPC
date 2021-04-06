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
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] --;
  }
  FenwickTree<long long> pre(100000);  
  FenwickTree<long long> suf(100000);
  long long S = 0;
  for (int i = 0; i < N; ++i) {
    suf.add(A[i], 1);
  }
  long long Ans = 0;
  for (int i = 0; i < N; ++i) {
    suf.add(A[i], -1);
    long long L = i - pre.query(A[i]);
    long long R = N - i - 1 - suf.query(A[i]);
    Ans += min(L, R);
    pre.add(A[i], 1);
  }
  cout << Ans << '\n';
}
