#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<int> cnt(101);
    for (int i = 0; i < N; ++i) {
      cnt[A[i]] ++;
    }
    vector<int> Ans;
    for (int i = 0; i < 101; ++i) {
      if (cnt[i] > 0) {
        cnt[i] --;
        Ans.push_back(i);
      }
    }
    for (int i = 0; i < 101; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        Ans.push_back(i);
      }
    }
    for (int i = 0; i < N; ++i) {
      cout << Ans[i] << " \n"[i == N - 1];
    }
  }
  return 0;
}
