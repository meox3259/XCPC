#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max() / 2;
class sgt {
  vector<long long> Max;
 public:
  sgt() {}
  sgt(int N) : Max(N * 4, -inf) {}
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
      return -inf;
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
  int N, W;
  cin >> N >> W;
  vector<int> S(N);
  vector<vector<int>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
    A[i].resize(S[i]);
    for (int j = 0; j < S[i]; ++j) {
      cin >> A[i][j];
    }
  }
  vector<long long> Sum(W + 1);
  for (int i = 0; i < N; ++i) {
    vector<pair<int, int>> vec;
    for (int j = 0; j < S[i]; ++j) {
      vec.emplace_back(A[i][j], j);
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int>> ());
    int BL = W;
    int BR = -W;
    if (S[i] * 2 > W) {
      sgt sgt(S[i]);
      for (int j = 0; j < S[i]; ++j) {
        sgt.update(0, S[i] - 1, 1, j, A[i][j]);
      }
      int ZL = W - S[i] - 1;
      int ZR = S[i];
      for (int j = 0; j < W; ++j) {
        int L = max(0, S[i] + j - W); 
        int R = min(S[i] - 1, j);
        long long Max = sgt.query(0, S[i] - 1, 1, L, R);
        if (Max >= 0) {
          Sum[j] += Max;
          Sum[j + 1] -= Max;
        } else if (j > ZL && j < ZR){
          Sum[j] += Max;
          Sum[j + 1] -= Max;
        }
      } 
      continue;
    }
    for (auto [V, P] : vec) {
      if (V <= 0) {
        break;
      }
      int L = P;
      int R = W - 1 - (S[i] - P - 1);
      Sum[L] += V;
      Sum[R + 1] -= V;
      int CL = max(L, BL);
      int CR = min(R, BR);
      if (CL <= CR) {
        Sum[CL] -= V;
        Sum[CR + 1] += V; 
      }
      BL = min(BL, L);
      BR = max(BR, R);
    }
  }
  for (int i = 0; i < W; ++i) {
    Sum[i + 1] += Sum[i];
  }
  for (int i = 0; i < W; ++i) {
    cout << Sum[i] << " \n"[i == W - 1];
  }
  return 0;
}
