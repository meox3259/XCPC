#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  vector<string> Ans0(H, string(W, '.'));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      Ans0[i][j] = S[i][j];
    }
  }
  for (int j = 0; j < W; ++j) {
    Ans0[0][j] = '#';
  }
  for (int j = 0; j < W; j += 2) {
    for (int i = 0; i < H - 1; ++i) {
      Ans0[i][j] = '#';
    }
  }
  vector<string> Ans1(H, string(W, '.'));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      Ans1[i][j] = S[i][j];
    }
  }
  for(int j = 0; j < W; ++j) {
    Ans1[H - 1][j] = '#';
  }
  for (int j = 1; j < W; j += 2) {
    for (int i = 1; i < H; ++i) {
      Ans1[i][j] = '#';
    }
  }
  for (int i = 0; i < H; ++i) {
    cout << Ans0[i] << '\n';
  }
  cout << '\n';
  for (int i = 0; i < H; ++i) {
    cout << Ans1[i] << '\n';
  }
}
