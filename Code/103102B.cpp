#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  int N = S.size();
  long long cnt = 0;
  long long zero = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (S[i] == '0') {
      zero ++;
    } else {
      cnt += zero;
    }
  }
  if (cnt % 3 == 0) {
    cout << "Bob" << '\n';
  } else {
    cout << "Alice" << '\n';
  }
}
