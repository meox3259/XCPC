#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
class sgt {
 private:
  vector<long long> Max;
 public:
  sgt() {}
  sgt(int N) : Max(N * 4 + 5, -Inf) {}
  void update(int l, int r, int x, int p, long long v) {
    if (l == r) {
      Max[x] = v;
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      update(l, mid, x << 1, p, v);
    } else {
      update(mid + 1, r, x << 1 | 1, p, v);
    }
    Max[x] = max(Max[x << 1], Max[x << 1 | 1]);
  }
  long long query(int l, int r, int x, int a, int b) {
    if (l > b || r < a) {
      return -Inf;
    }
    if (l >= a && r <= b) {
      return Max[x];
    }
    int mid = l + r >> 1;
    return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  vector<long long> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  vector<long long> dp(N, -Inf);
  vector<int> st;
  sgt sgt(N);
  for (int i = 0; i < N; ++i) {
    while (!st.empty() && H[st.back()] > H[i]) {
      int Y = st.back();
      dp[i] = max(dp[i], dp[st.back()] + B[i]); 
      st.pop_back();
      int X = st.empty() ? 0 : st.back();
      dp[i] = max(dp[i], sgt.query(0, N - 1, 1, X, Y) + B[i]);
    } 
    if (st.empty()) {
      dp[i] = max(dp[i], B[i]);
    } else {
      dp[i] = max(dp[i], dp[st.back()] + B[i]);
      dp[i] = max(dp[i], dp[st.back()]);
    }
    st.push_back(i);
    sgt.update(0, N - 1, 1, i, dp[i]);
  }
  cout << dp[N - 1] << '\n';
}
