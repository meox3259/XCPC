#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
class sgt { 
 private:
  vector<long long> tag;
  vector<long long> Min;
 public:
  sgt() {}
  sgt(int N) : tag(N * 4), Min(N * 4) {}
  void pushdown(int X) {
    tag[X << 1] += tag[X];
    tag[X << 1 | 1] += tag[X];
    Min[X << 1] += tag[X];
    Min[X << 1 | 1] += tag[X];
    tag[X] = 0;
  }
  void update(int L, int R, int X, int A, int B, long long V) {
    if (L > B || R < A) {
      return;
    }
    if (L >= A && R <= B) {
      tag[X] += V;
      Min[X] += V;
      return;
    }
    pushdown(X);
    int Mid = L + R >> 1;
    update(L, Mid, X << 1, A, B, V);
    update(Mid + 1, R, X << 1 | 1, A, B, V);
    Min[X] = min(Min[X << 1], Min[X << 1 | 1]); 
  }  
  long long query(int L, int R, int X, int A, int B) {
    if (L > B || R < A) {
      return Inf;
    }
    if (L >= A && R <= B) {
      return Min[X];
    }
    pushdown(X);
    int Mid = L + R >> 1;
    return min(query(L, Mid, X << 1, A, B), query(Mid + 1, R, X << 1 | 1, A, B));
  }
  long long all() {
    return Min[1];
  }
};
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] --;
  }
  vector<int> P(N, -1);
  vector<int> lst(N, -1);
  for (int i = 0; i < N; ++i) {
    lst[i] = P[A[i]];
    P[A[i]] = i;
  }
  vector<vector<long long>> dp(K + 1, vector<long long> (N + 1, Inf));
  dp[0][0] = 0;
  long long Ans = 0;
  for (int k = 0; k < K; ++k) {
    sgt sgt(N + 1);
    for (int i = 0; i <= N; ++i) {
      sgt.update(0, N, 1, i, i, dp[k][i]);
    }
    for (int i = 0; i < N; ++i) {
      sgt.update(0, N, 1, 0, lst[i], i - lst[i]); 
      dp[k + 1][i + 1] = sgt.all();
    }
  }
  cout << dp[K][N] << '\n';
}
