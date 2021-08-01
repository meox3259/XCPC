#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int N, M;
    cin >> N >> M;
    if (N == 0) {
      cout << M + 1 << '\n';
    } else if (M < N) {
      cout << 0 << '\n'; 
    } else {
      int bN = -1;  
      for (int i = 0; i < 31; ++i) {
        if (N >> i & 1) {
          bN = i;
        }
      }
      int bM = -1;
      for (int i = 0; i < 31; ++i) {
        if (M >> i & 1) {
          bM = i;
        }
      }
      vector<pair<long long, long long>> seg;
      for (int i = bM; i >= 0; --i) {
        if (M >> i & 1) {
          long long S = 0;  
          for (int j = i + 1; j <= bM; ++j) {
            S |= ((N >> j & 1) ^ (M >> j & 1)) << j;
          }
          S |= (N >> i & 1) << i;
          seg.emplace_back(S + 0, S + (1 << i) - 1);
        } 
      }
      seg.emplace_back(M ^ N, M ^ N);
      sort(seg.begin(), seg.end());
      int Max = 0;
      bool ok = false;
      for (auto [L, R] : seg) {
        if (Max + 1 < L) {
          ok = true;
          cout << Max + 1 << '\n';
          break;
        } 
        Max = max(Max, (int)R);
      }
      if (!ok) {
        cout << Max + 1 << '\n'; 
      }
    }
  }
}
