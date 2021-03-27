#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;
  X --;
  Y --;
  vector<string> S(H);
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  int Ans = 0;
  for (int i = Y; i < W; ++i) {
    if (S[X][i] == '#') {
      break;
    }
    Ans ++;
  }
  if (S[X][Y] == '.') {
    Ans --;
  }
  for (int i = Y; i >= 0; --i) {
    if (S[X][i] == '#') {
      break;
    }
    Ans ++;
  }
  if (S[X][Y] == '.') {
    Ans --;
  }
  for (int i = X; i >= 0; --i) {
    if (S[i][Y] == '#') {
      break;
    }
    Ans ++;
  }
  if (S[X][Y] == '.') {
    Ans --;
  }
  for (int i = X; i < H; ++i) {
    if (S[i][Y] == '#') {
      break;
    }
    Ans ++;
  }
  if (S[X][Y] == '.') {
    Ans --;
  }
  if (S[X][Y] == '.') {
    Ans ++;
  }
  cout << Ans << '\n';
}
