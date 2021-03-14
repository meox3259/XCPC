#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    P[i] --;
  }
  vector<int> f(N);
  vector<int> g(N);
  for (int i = 0; i < N - 1; ++i) {
    if (P[i + 1] > P[i]) {
      f[i + 1] = f[i] + 1;
    } else {
      g[i + 1] = g[i] + 1; 
    }
  }
  vector<int> rev(N);
  for (int i = N - 1; i >= 1; --i) {
    if (P[i - 1] > P[i]) {
      rev[i - 1] = rev[i] + 1;
    }
  }
  multiset<int> S;
  for (int i = 1; i < N; ++i) {
    if (i == N - 1) {
      S.insert(max(f[i], g[i])); 
    } else {
      if (P[i] > P[i - 1] && P[i] > P[i + 1]) {
        S.insert(f[i]);
      }
      if (P[i] < P[i - 1] && P[i] < P[i + 1]) {
        S.insert(g[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < N - 1; ++i) {
    if (P[i] > P[i - 1] && P[i] > P[i + 1]) {
      if (f[i] < rev[i]) {
        S.erase(S.find(f[i]));
        S.erase(S.find(rev[i]));
        S.insert(rev[i] - ((rev[i] & 1) ^ 1));
        if (*S.rbegin() < f[i]) {
          ans ++;
        }
        S.insert(f[i]);
        S.insert(rev[i]);
        S.erase(S.find(rev[i] - ((rev[i] & 1) ^ 1)));
      } else {
        S.erase(S.find(rev[i]));
        S.erase(S.find(f[i]));
        S.insert(f[i] - ((f[i] & 1) ^ 1));
        if (*S.rbegin() < rev[i]) {
          ans ++;
        }
        S.insert(rev[i]);
        S.insert(f[i]);
        S.erase(S.find(f[i] - ((f[i] & 1) ^ 1)));
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
