#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<int> To(N, -1);
    vector<int> deg(N);
    for (int i = 0; i < N; ++i) {
      To[i] = i - A[i]; 
      deg[To[i]] ++;
    }
    queue<int> Q;
    vector<bool> vis(N);
    for (int i = 0; i < N; ++i) {
      if (deg[i] == 0) {
        Q.push(i);
      }
    }
    while (!Q.empty()) {
      int X = Q.front();
      Q.pop();
      vis[X] = true;
      if (! --deg[To[X]]) {
        Q.push(To[X]);
      }
    }
    vector<int> Ans;
    for (int i = 0; i < N; ++i) {
      if (!vis[i]) {
        int X = i;
        while (!vis[X]) {
          Ans.push_back(X);
          vis[X] = true;
          X = To[X];
        }
      }
    }
    cout << Ans.size() << '\n';
    for (int i = 0; i < Ans.size(); ++i) {
      cout << Ans[i] + 1 << " \n"[i + 1 == Ans.size()];
    }
  }
}
