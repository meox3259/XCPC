#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<set<int>> S(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    S[X].insert(Y);
    S[Y].insert(X);
  }
  for (int i = 0; i < N; ++i) {
    S[i].insert(i);
  }
  vector<int> is(N);
  int Ans = 0;
  for (int i = 0; i < N; ++i) {
    if (*S[i].rbegin() == i) {
      is[i] = 1;
      Ans ++;
    }
  }
  int Q;
  cin >> Q;
  while (Q --> 0) {
    int type;
    cin >> type;
    if (type == 1) {
      int X, Y;
      cin >> X >> Y;
      X --;
      Y --;
      S[X].insert(Y);
      S[Y].insert(X);
      if (*S[X].rbegin() > X) {
        if (is[X]) {
          is[X] = 0;
          Ans --;
        }
      }
      if (*S[Y].rbegin() > Y) {
        if (is[Y]) {
          is[Y] = 0;
          Ans --;
        }
      }
    }
    if (type == 2) {
      int X, Y;
      cin >> X >> Y;
      X --;
      Y --;
      S[X].erase(Y);
      S[Y].erase(X);
      if (*S[X].rbegin() == X) {
        if (!is[X]) {
          is[X] = 1;
          Ans ++;
        }
      }
      if (*S[Y].rbegin() == Y) {
        if (!is[Y]) {
          is[Y] = 1;
          Ans ++;
        }
      }
    }
    if (type == 3) {
      cout << Ans << '\n'; 
    }
  }
}
