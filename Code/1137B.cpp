#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S, T;
  cin >> S >> T;
  int N = S.size();
  int M = T.size();
  vector<int> cnt(2);
  for (char C : S) {
    cnt[C - '0'] ++;
  }
  vector<int> Nxt(M, -1);
  Nxt[0] = -1;
  for (int i = 1, j = -1; i < M; ++i) {
    while (j != -1 && T[i] != T[j + 1]) {
      j = Nxt[j];
    } 
    if (T[j + 1] == T[i]) {
      j ++;
    }
    Nxt[i] = j;
  }
  string Ans = "";
  vector<int> c(2);
  for (char C : T) {
    c[C - '0'] ++;
  }
  if (cnt[0] >= c[0] && cnt[1] >= c[1]) {
    cnt[0] -= c[0];
    cnt[1] -= c[1];
    Ans += T;
  }
  int L = M - 1 - Nxt[M - 1];
  string B = T.substr(M - L, L);
  vector<int> d(2);
  for (char C : B) {
    d[C - '0'] ++;
  }
  while (cnt[0] >= d[0] && cnt[1] >= d[1]) {
    Ans += B;
    cnt[0] -= d[0];
    cnt[1] -= d[1];
  }
  Ans += string(cnt[0], '0');
  Ans += string(cnt[1], '1');
  cout << Ans << '\n';
}
