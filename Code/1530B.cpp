#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int H, W;
    cin >> W >> H;
    vector<string> S(W, string(H, '0'));
    if (H % 2 == W % 2) {
      if (H % 2 == 1) {
        for (int i = 0; i < H; i += 2) {
          S[0][i] = S[W - 1][i] = '1';
        }
        for (int i = 0; i < W; i += 2) {
          S[i][0] = S[i][H - 1] = '1';
        }
      } else {
        for (int i = 1; i < H - 1; i += 2) {
          S[0][i] = '1';
        } 
        for (int i = 1; i < W - 1; i += 2) {
          S[i][H - 1] = '1';
        }
        for (int i = H - 2; i >= 1; i -= 2) {
          S[W - 1][i] = '1';
        }
        for (int i = W - 2; i >= 1; i -= 2) {
          S[i][0] = '1';
        }
      }
    } else {
      if (W % 2 == 1) {
        for (int i = 1; i < H; i += 2) {
          S[0][i] = '1';
          S[W - 1][H - i - 1] = '1';
        } 
        for (int i = 0; i < W - 2; i += 2) {
          S[i][H - 1] = '1';
          S[W - i - 1][0] = '1';
        }
      } else {
        for (int i = 0; i < W; i += 2) {
          S[i][0] = '1';
          S[W - i - 1][H - 1] = '1';
        } 
        for (int i = 0; i < H - 2; i += 2) {
          S[0][i] = '1';
          S[W - 1][H - i - 1] = '1';
        }
      } 
    } 
    for (int i = 0; i < W; ++i) {
      cout << S[i] << '\n';
    }
    cout << '\n';
  }
}
