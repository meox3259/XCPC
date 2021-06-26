#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --) {
    int N;
    cin >> N;
    if (N <= 3) {
      cout << "Bob" << '\n';
    } else {
      if (N % 2 == 1) {
        cout << "Bob" << '\n';
      } else {
        int two = 0; 
        while (N % 2 == 0) {
          N /= 2;
          two ++;
        }
        if (N == 1) {
          if (two & 1) {
            cout << "Bob" << '\n';
          } else {
            cout << "Alice" << '\n';
          }
        } else {
          cout << "Alice" << '\n';
        }
      }
    }
  }
}
