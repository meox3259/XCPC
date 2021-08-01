#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  int K = N + M;
  vector<int> P(K);
  for (int i = 0; i < K; ++i) {
    cin >> P[i];
    P[i] --;
  }
  vector<bool> vis(K);
  int Ans = K;
  int c1 = 0;
  int c2 = 0;
  for (int i = 0; i < K; ++i) {
    if (!vis[i]) {
      int j = i;
      int cnt = 0;
      bool ok1 = false;
      bool ok2 = false;
      while (!vis[j]) {
        if (j < N) {
          ok1 = true;
        }
        cnt ++;
        if (j >= N) {
          ok2 = true;
        }
        vis[j] = true;
        j = P[j];
      }
      if (cnt == 1 || (ok1 && ok2)) {
        Ans --; 
      } else if (ok1) {
        c1 ++;
      } else if (ok2) {
        c2 ++;
      }
    }
  }
  Ans += abs(c1 - c2);
  cout << Ans << '\n';
}
