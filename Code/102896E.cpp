#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  while (N --) {
    long long B, D;
    cin >> B >> D;
    long long G = __gcd(B, D);
    long long X = D / G;
    cout << (B - 1) / X << '\n';
  }
  return 0;
}
