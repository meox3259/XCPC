#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    string S;
    cin >> S;
    int Ans = 0;
    for (char C : S) {
      Ans = max(Ans, C - '0');
    }
    cout << Ans << '\n';
  }
}
