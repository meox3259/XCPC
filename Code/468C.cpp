#include <bits/stdc++.h>
using namespace std;
const long long Inf = 1000000000000000000;
int main() {
  long long A;
  cin >> A;
  long long L = A - 9LL * Inf % A * 9 % A;
  long long R = Inf + L - 1; 
  cout << L << ' ' << R << '\n';
}
