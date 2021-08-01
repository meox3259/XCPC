#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int> :: max() / 2;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N, INF) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] = min(v[i - 1], val);
    }
  }
  T query(int p) {
    T sum = INF;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum = min(sum, v[i - 1]);
    }
    return sum;
  }
  T range(int L, int R) {
    return query(R) - query(L - 1);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<vector<int>> R(N, vector<int> (5));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> R[i][j];
      }
    }
    vector<bool> mark(N, true);
    for (int a = 0; a < 5; ++a) {
      vector<int> id(N);
      iota(id.begin(), id.end(), 0);
      sort(id.begin(), id.end(), [&] (int i, int j) {
        return R[i][a] < R[j][a];
      });
      for (int b = a + 1; b < 5; ++b) {
        vector<int> vec;
        for (int i = 0; i < N; ++i) {
          vec.push_back(R[i][b]);
        }
        sort(vec.begin(), vec.end());
        auto Rank = [&] (int V) -> int {
          return lower_bound(vec.begin(), vec.end(), V) - vec.begin();
        };
        for (int c = b + 1; c < 5; ++c) {
          FenwickTree<int> fw(N);
          for (int i = 0; i < N; ++i) {
            if (fw.query(Rank(R[id[i]][b])) < R[id[i]][c]) {
              mark[id[i]] = false;
            } 
            fw.add(Rank(R[id[i]][b]), R[id[i]][c]);
          }
        }
      }
    }
    bool ok = false;
    for (int i = 0; i < N; ++i) {
      if (mark[i]) {
        ok = true;
        cout << i + 1 << '\n';
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    }
  }
}
