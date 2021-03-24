#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<vector<int>> fac(N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = i + i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }
  vector<int> Ans(N + 1);
  vector<int> mark(N + 2);
  for (int i = 1; i <= N; ++i) {
    for (int j : fac[i]) {
      mark[Ans[j]] = i;
    }
    int X = 1;
    while (mark[X] == i) {
      X ++;
    }
    Ans[i] = X;
  }
  for (int i = 1; i <= N; ++i) {
    cout << Ans[i] << " \n"[i == N];
  }
}
