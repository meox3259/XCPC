#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    long long N;
    cin >> N;
    int two = 0;
    while (N % 2 == 0) {
      N /= 2;
      two ++;
    }
    if (two == 0) {
      cout << "Odd" << '\n';
    }
    if (two == 1) {
      cout << "Same" << '\n';
    }
    if (two >= 2) {
      cout << "Even" << '\n';
    }
  }
}
