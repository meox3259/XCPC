#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
      P[i] --;
    }
    vector<int> cnt(N);
    for (int i = 0; i < N; ++i) {
      cnt[(i - P[i] + N) % N] ++;
    }
    vector<int> Ans;
    for (int k = 0; k < N; ++k) {
      if (cnt[k] >= N / 3) {
        vector<bool> vis(N);  
        vector<int> shift(N);
        for (int i = 0; i < N; ++i) {
          shift[(i - k + N) % N] = P[i]; 
        }
        int cycle = 0;
        for (int i = 0; i < N; ++i) {
          if (!vis[i]) {
            int j = i;  
            while (!vis[j]) {
              vis[j] = true;
              j = shift[j]; 
            }
            cycle ++;
          }  
        }
        if (N - cycle <= M) {
          Ans.push_back(k);
        }
      }
    }
    cout << Ans.size();
    for (int i = 0; i < Ans.size(); ++i) {
      cout << ' ' << Ans[i];
    }
    cout << '\n';
  }
}
