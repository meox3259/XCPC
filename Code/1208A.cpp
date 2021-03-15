#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --) {
    int A, B, N;
    cin >> A >> B >> N;
    if (N % 3 == 0) {
      cout << A << '\n';
    } 
    if (N % 3 == 1) {
      cout << B << '\n';
    }
    if (N % 3 == 2) {
      cout << (A ^ B) << '\n';
    }
  }
  return 0;
}
