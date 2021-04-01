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
  T range(int L, int R) {
    return query(R) - query(L - 1);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  vector<int> dfn(N, -1);
  vector<int> low(N, -1);
  vector<int> st;
  vector<bool> in(N);
  vector<int> Max(N, -1);
  int dfs_clock = 0;
  auto dfs = [&] (auto &&f, int X, int Par) -> void {
    dfn[X] = low[X] = dfs_clock ++;
    st.push_back(X);
    for (int Y : adj[X]) {
      if (Y != Par) {
        if (dfn[Y] == -1) {
          f(f, Y, X);
        } else if (!in[Y]) {
          vector<int> cir;
          while(true) {
            int Z = st.back(); 
            st.pop_back();
            in[Z] = true;
            cir.push_back(Z);
            if (Z == Y) {
              break;
            }
          }
          if (cir.size() > 1) {
            int A = *min_element(cir.begin(), cir.end());
            int B = *max_element(cir.begin(), cir.end());
            Max[B] = max(Max[B], A);
          }
        }
      }
    }
    if (!in[X]) {
      st.pop_back();
    }
  };  
  for (int i = 0; i < N; ++i) {
    if (dfn[i] == -1) {
      dfs(dfs, i, -1);
    }
  }
  for (int i = 0; i < N - 1; ++i) {
    Max[i + 1] = max(Max[i + 1], Max[i]);
  }
  int Q;
  cin >> Q;
  vector<tuple<int, int, int>> queries;
  for (int i = 0; i < Q; ++i) {
    int L, R;
    cin >> L >> R;
    L --;
    R --;
    queries.emplace_back(R, L, i);
  }
  sort(queries.begin(), queries.end());
  vector<long long> Ans(Q);
  FenwickTree<long long> C(N);
  FenwickTree<long long> S(N);
  int j = 0;
  for (auto [R, L, i] : queries) {
    while (j <= R) {
      if (Max[j] != -1) {
        C.add(Max[j], 1);
        S.add(Max[j], Max[j]);
      }
      j ++;
    } 
    long long Low = R - L + 1 - C.range(L, R);
    Ans[i] += 1LL * (L + R) * (R - L + 1) / 2;
    Ans[i] -= Low * (L - 1);
    Ans[i] -= S.range(L, R);
  }
  for (int i = 0; i < Q; ++i) {
    cout << Ans[i] << '\n';
  }
}
