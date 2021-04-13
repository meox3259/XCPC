#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  int Len = 0;
  for (int i = 0; i < N; ++i) {
    map<pair<int, int>, int> cnt;
    for (int j = 0; j < N; ++j) {
      if (j != i) {
        int DX = X[i] - X[j];
        int DY = Y[i] - Y[j];
        int G = __gcd(DX, DY);
        DX /= G;
        DY /= G;
        if (DX == 0 || DY == 0) {
          DX = abs(DX);
          DY = abs(DY);
        }
        if (DY < 0) {
          DY = -DY;
          DX = -DX;
        }
        cnt[ {DX, DY} ] ++;
      }
    }
    for (auto O : cnt) {
      Len = max(Len, O.second + 1);
    }
  }
  int RLen = N - Len;
  int Ans = N / 3;
  if (RLen * 2 < Len) {
    Ans = min(Ans, RLen);
  }
  cout << Ans << '\n';
}

