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
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  unordered_map<char, int> mp;
  mp['R'] = 0;
  mp['S'] = 1;
  mp['P'] = 2;
  vector<FenwickTree<int>> fw(3, FenwickTree<int> (N));
  vector<set<int>> P(3);
  for (int i = 0; i < N; ++i) {
    int A = mp[S[i]];   
    fw[A].add(i, 1);
    P[A].insert(i);
  }
  auto calc = [&] (int X) -> int {
    int ret = 0;
    int W = (X + 1) % 3;
    int L = (X + 2) % 3;
    if (P[L].empty()) {
      return fw[X].query(N - 1); 
    }
    if (P[W].empty()) {
      return 0;
    }
    int A = *P[W].begin();
    int B = *P[W].rbegin();
    ret += fw[X].query(B - 1) - fw[X].query(A);
    A = min(A, *P[L].begin());
    B = max(B, *P[L].rbegin());
    ret += fw[X].query(A - 1);
    ret += fw[X].query(N - 1) - fw[X].query(B);
    return ret;
  };
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += calc(i);
  }
  cout << ans << '\n';
  while (Q --) {
    int i;
    char C;
    cin >> i >> C;
    i --;
    P[mp[S[i]]].erase(i);
    fw[mp[S[i]]].add(i, -1);
    S[i] = C;
    P[mp[S[i]]].insert(i);
    fw[mp[S[i]]].add(i, 1);
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
      ans += calc(i);
    }
    cout << ans << '\n';
  }
  return 0;
}
