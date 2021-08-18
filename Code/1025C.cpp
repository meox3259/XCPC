#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  string T = S + S; 
  int N = S.size();
  string A = "";
  string B = "";
  for (int i = 0; i < N + N; ++i) {
    if (i & 1) {
      A += 'b';
      B += 'w';
    } else {
      A += 'w';
      B += 'b';
    }
  }
  int Ans = 0;
  int cnt = 0;
  for (int i = 0; i < N + N; ++i) {
    if (T[i] == A[i]) {
      cnt ++;
    } else {
      cnt = 0;
    }
    Ans = max(Ans, cnt);
  }
  cnt = 0;
  for (int i = 0; i < N + N; ++i) {
    if (T[i] == B[i]) {
      cnt ++;
    } else {
      cnt = 0;
    }
    Ans = max(Ans, cnt);
  }
  cout << min(Ans, N) << '\n';
}
