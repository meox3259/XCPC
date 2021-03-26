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
    vector<int> Q(N);
    for (int i = 0; i < N; ++i) {
      cin >> Q[i];
      Q[i] --;
    }
    set<int> S;
    for (int i = 0; i < N; ++i) {
      S.insert(i);
    }
    for (int i = 0; i < N; ++i) {
      if (S.find(Q[i]) != S.end()) {
        cout << Q[i] + 1 << " \n"[i == N - 1]; 
        S.erase(Q[i]);
      } else {
        cout << *S.begin() + 1 << " \n"[i == N - 1];
        S.erase(S.begin());
      }
    }
    for (int i = 0; i < N; ++i) {
      S.insert(i);
    }
    for (int i = 0; i < N; ++i) {
      int V = *prev(S.upper_bound(Q[i]));
      cout << V + 1 << " \n"[i == N - 1];
      S.erase(V);
    }
  }
}
