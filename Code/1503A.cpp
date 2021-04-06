#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string Ans1(N, '1');
    string Ans2(N, '1');
    int cur = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] == '0') {
        if (cur == 0) {
          Ans1[i] = '(';
          Ans2[i] = ')';
        } else {
          Ans1[i] = ')';
          Ans2[i] = '(';
        }
        cur ^= 1;
      } 
    }
    vector<int> one;
    for (int i = 0; i < N; ++i) {
      if (S[i] == '1') {
        one.push_back(i);
      }
    }
    int M = one.size();
    for (int i = 0; i < M / 2; ++i) {
      Ans1[one[i]] = '(';
      Ans2[one[i]] = '(';
    }
    for (int i = M / 2; i < M; ++i) {
      Ans1[one[i]] = ')';
      Ans2[one[i]] = ')';
    }
    auto check = [&] (string S) -> bool {
      int pre = 0;
      for (char C : S) {
        if (C == '(') {
          pre ++;
        } else {
          pre --;
        }
        if (pre < 0) {
          return false;
        }
      }
      return pre == 0;
    };
    if (check(Ans1) && check(Ans2)) {
      cout << "YES" << '\n';
      cout << Ans1 << '\n';
      cout << Ans2 << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
