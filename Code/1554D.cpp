#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    if (N == 1) {
      cout << 'a' << '\n';
      continue;
    }
    if (N % 2 == 0) {
      int X = (N - 1) / 2; 
      int Y = N - 1 - X;
      string Ans = "";
      for (int i = 0; i < X; ++i) {
        Ans += 'a';
      }
      Ans += 'b';
      for (int i = 0; i < Y; ++i) {
        Ans += 'a';
      }
      cout << Ans << '\n';
    } else {
      int X = (N - 2) / 2; 
      int Y = N - 2 - X;
      string Ans = "";
      for (int i = 0; i < X; ++i) {
        Ans += 'a';
      }
      Ans += 'b';
      Ans += 'c';
      for (int i = 0; i < Y; ++i) {
        Ans += 'a';
      }
      cout << Ans << '\n';
    }
  }
}
