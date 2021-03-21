#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> X(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  map<int, int> id;
  for (int i = 0; i < N; ++i) {
    id[X[i]] = i;
  }
  set<int> S;
  for (int i : X) {
    S.insert(i);
  }
  while (M --> 0) {
    int A, L;
    cin >> A >> L;
    A --;
    int cur = X[A];
    while (true) {
      int X = *prev(S.upper_bound(cur + L));
      L -= abs(X - cur);
      int Y = *S.lower_bound(X - L);
      L -= abs(X - Y);
      if (cur == X && cur == Y) {
        break;
      }
      if (Y == cur) {
        L %= (X - Y) * 2;
      } 
      cur = Y;
    }
    cout << id[cur] + 1 << '\n';
  }
}
