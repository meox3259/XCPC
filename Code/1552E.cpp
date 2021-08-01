#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> C(N * K);
  for (int i = 0; i < N * K; ++i) {
    cin >> C[i];
    C[i] --;
  }
  vector<int> last(N, -1);
  vector<int> pre(N * K, -1);
  for (int i = 0; i < N * K; ++i) {
    pre[i] = last[C[i]];
    last[C[i]] = i;
  }
  vector<tuple<int, int, int>> Ans;
  vector<bool> mark(N * K);
  vector<bool> vis(N);
  while (true) {
    if (Ans.size() == N) {
      break;
    }
    int Right = -1;
    for (int i = 0; i < N * K; ++i) {
      if (!vis[C[i]] && pre[i] > Right) {
        Ans.emplace_back(C[i], pre[i], i);
        vis[C[i]] = true;
        Right = i;
      }
    }
  }
  sort(Ans.begin(), Ans.end());
  for (auto [W, L, R] : Ans) {
    cout << L + 1 << ' ' << R + 1 << '\n';
  }
}
