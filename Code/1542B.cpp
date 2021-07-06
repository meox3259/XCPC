#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    long long N, A, B;
    cin >> N >> A >> B;
    if (A == 1) {
      if ((N - 1) % B == 0) {
        cout << "Yes" << '\n'; 
      } else {
        cout << "No" << '\n';
      }
    } else {
      bool ok = false;
      long long pw = 1; 
      while (pw <= N) {
        if ((N - pw) % B == 0) {
          ok = true;
        }
        pw *= A;
      } 
      if (ok) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }
}
