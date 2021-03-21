#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  for (char C : S) {
    if (C == '.') {
      break;
    }
    cout << C;
  }
  cout << '\n';
}
