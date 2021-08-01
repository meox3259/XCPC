#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T(S);
    sort(T.begin(), T.end());
    int Ans = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] != T[i]) {
        Ans ++;
      }
    }
    cout << Ans << '\n';
  }
}
