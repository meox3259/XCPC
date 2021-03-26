#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    string S;
    cin >> S;
    int N = S.size();
    map<char, vector<int>> mp;
    vector<char> V;
    for (int i = 0; i < N; ++i) {
      mp[S[i]].push_back(i);
      V.push_back(S[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    int M = V.size();
    vector<bool> vis(M);
    int cur = 0;
    string Ans = "";
    for (int i = 0; i < M; ++i) {
      for (int j = M - 1; j >= 0; --j) {
        if (!vis[j]) {
          int P = *lower_bound(mp[V[j]].begin(), mp[V[j]].end(), cur);
          bool ok = true;
          for (int k = 0; k < M; ++k) {
            if (!vis[k] && mp[V[k]].back() < P) {
              ok = false;
              break;
            }
          }
          if (ok) {
            Ans += V[j];
            vis[j] = true;
            cur = P;
            break;
          }
        }
      } 
    }
    cout << Ans << '\n';
  }
}
