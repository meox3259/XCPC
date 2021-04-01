#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
class sgt {
 private:
  vector<bool> cover;
  vector<long long> sum;
  vector<int> Min;
  vector<int> tag;
 public:
  sgt() {}
  sgt(int N) : cover(N * 4), sum(N * 4), tag(N * 4), Min(N * 4, Inf) {}
  void pushdown(int X, int L, int R) {
    if (cover[X]) {
      int Mid = L + R >> 1;
      cover[X << 1] = true;
      cover[X << 1 | 1] = true;
      tag[X << 1] = tag[X];
      tag[X << 1 | 1] = tag[X];
      sum[X << 1] = 1LL * (Mid - L + 1) * tag[X];
      sum[X << 1 | 1] = 1LL * (R - Mid) * tag[X];
      Min[X << 1] = tag[X];
      Min[X << 1 | 1] = tag[X];
      cover[X] = false;
    } 
  }
  void update(int L, int R, int X, int A, int B, int V) {
    if (L > B || R < A) {
      return; 
    }
    if (L >= A && R <= B) {
      cover[X] = true;
      tag[X] = V;
      sum[X] = 1LL * (R - L + 1) * V;
      Min[X] = V; 
      return; 
    }
    pushdown(X, L, R);
    int Mid = L + R >> 1;
    update(L, Mid, X << 1, A, B, V);
    update(Mid + 1, R, X << 1 | 1, A, B, V);
    sum[X] = sum[X << 1] + sum[X << 1 | 1]; 
    Min[X] = min(Min[X << 1], Min[X << 1 | 1]);
  }
  int find(int L, int R, int X, int V) {
    if (L == R) {
      if (Min[X] <= V) {
        return L;
      } else {
        return -1;
      }
    }
    pushdown(X, L, R);
    int Mid = L + R >> 1;
    if (Min[X << 1] <= V) {
      return find(L, Mid, X << 1, V); 
    } else {
      return find(Mid + 1, R, X << 1 | 1, V);
    }
  }
  long long query(int L, int R, int X, int A, int B) {
    if (L > B || R < A) {
      return 0;
    }
    if (L >= A && R <= B) {
      return sum[X];
    }
    pushdown(X, L, R);
    int Mid = L + R >> 1;
    return query(L, Mid, X << 1, A, B) + query(Mid + 1, R, X << 1 | 1, A, B);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string S;
  cin >> S;
  sgt sgt(N);
  long long Ans = 0;
  int one = 0;
  vector<long long> dp(N);
  for (int i = 0; i < N; ++i) {
    if (S[i] == '0') {
      for (int j = 0; j < one; ++j) {
        sgt.update(0, N - 1, 1, i - j - 1, i - j - 1, j + 1);
      }
      sgt.update(0, N - 1, 1, i, i, 0);
      one = 0;
      if (i > 0) {
        dp[i] = dp[i - 1];
        Ans += dp[i - 1];
      }
    } else {
      one ++;
      dp[i] += 1LL * one * (one + 1) / 2;
      int P = sgt.find(0, N - 1, 1, one);
      if (P != -1) {
        sgt.update(0, N - 1, 1, P, i - one, one); 
      }
      dp[i] += sgt.query(0, N - 1, 1, 0, i - one);
      Ans += dp[i];
    }
  }
  cout << Ans << '\n';
}
