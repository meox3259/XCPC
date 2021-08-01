#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long> :: max() / 2;
class sgt {
 public:
  vector<int> Min;
  vector<int> tag;
  sgt() {}
  sgt(int N) : Min(N * 4 + 5), tag(N * 4 + 5) {}
  void pushdown(int X) {
    tag[X << 1] += tag[X];
    tag[X << 1 | 1] += tag[X];
    Min[X << 1] += tag[X];
    Min[X << 1 | 1] += tag[X];
    tag[X] = 0;
  }
  void update(int L, int R, int X, int A, int B, int V) {
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
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> L(N);
  vector<int> R(N);
  vector<int> W(N);
  for (int i = 0; i < N; ++i) {
    cin >> L[i] >> R[i] >> W[i];
  }
  vector<tuple<int, int, int>> S;
  for (int i = 0; i < N; ++i) {
    S.emplace_back(L[i], R[i], W[i]); 
  }
  sort(S.begin(), S.end(), [&] (const auto &X, const auto &Y) -> bool {
    return get<2>(X) < get<2>(Y);
  }); 
  sgt sgt(M + 1);
  sgt.update(1, M, 1, 1, 1, N);
  int Ans = 1000000000;
  for (int i = 0, j = 0; i < N; ++i) {
    sgt.update(1, M, 1, get<0>(S[i]) + 1, get<1>(S[i]), 1);
    while (j < i) {
      sgt.update(1, M, 1, get<0>(S[j]) + 1, get<1>(S[j]), -1);
      if (sgt.Min[1] <= 0) {
        sgt.update(1, M, 1, get<0>(S[j]) + 1, get<1>(S[j]), 1);
        break;
      }
      j ++;
    } 
    if (sgt.Min[1] >= 1) {
      Ans = min(Ans, get<2>(S[i]) - get<2>(S[j]));
    }
  }
  cout << Ans << '\n';
}
