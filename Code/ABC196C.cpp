#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N;
  cin >> N;
  int Ans = 0;
  for (int i = 1; i <= 2000000; ++i) {
    long long ten = 1;
    int T = i;
    while (T) {
      T /= 10;
      ten *= 10;
    }
    if (i + ten * i <= N) {
      Ans ++;
    }
  }
  cout << Ans << '\n';
}
