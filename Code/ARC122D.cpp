#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N * 2);
  for (int i = 0; i < N * 2; ++i) {
    cin >> A[i];
  }
  vector<vector<int>> ch(N * 62 + 1, vector<int> (2));
  vector<int> sz(N * 62 + 1);
  vector<bool> isEnd(N * 62 + 1);
  vector<int> Val(N * 62 + 1);
  int Pool = 1;
  for (int V : A) {
    int cur = 1;
    for (int j = 30; j >= 0; --j) {
      int W = (V >> j & 1);
      if (!ch[cur][W]) {
        ch[cur][W] = ++Pool;
      }
      cur = ch[cur][W];
      sz[cur] ++;
    }
    isEnd[cur] = true;
    Val[cur] = V;
  }
  auto dfs = [&] (auto &&f, int X, int bit) -> int {
    if (X == 0) {
      return 0;
    }
    if (sz[ch[X][0]] % 2 == 0 && sz[ch[X][1]] % 2 == 0) {
      return max(f(f, ch[X][0], bit - 1), f(f, ch[X][1], bit - 1));
    }
    queue<int> Q;
    Q.push(ch[X][1]);
    vector<int> R;
    while (!Q.empty()) {
      int U = Q.front();
      Q.pop();
      if (isEnd[U]) {
        R.push_back(Val[U]); 
      }  
      for (int i = 0; i < 2; ++i) {
        if (ch[U][i] != 0) {
          Q.push(ch[U][i]);
        }
      }
    }
    int ret = INF;
    for (int V : R) {
      int cur = ch[X][0]; 
      int curV = 1 << bit;
      for (int i = bit - 1; i >= 0; --i) {
        int W = (V >> i & 1);   
        if (ch[cur][W] != 0) {
          cur = ch[cur][W];
        } else {
          cur = ch[cur][W ^ 1];
          curV += 1 << i;
        }
      }
      ret = min(ret, curV);
    }
    return ret;
  };
  cout << dfs(dfs, 1, 30) << '\n';
}
