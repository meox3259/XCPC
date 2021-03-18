#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B, C;
  cin >> A >> B >> C;
  cout << (C * 2 + min(A, B) * 2 + (A != B)) << '\n';
  return 0;
}
