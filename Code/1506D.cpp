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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    map<int, int> cnt;
    for (int i : A) {
      cnt[i] ++;
    }
    int Max = 0;
    for (auto o : cnt) {
      Max = max(Max, o.second);
    }
    cout << max(N & 1, Max * 2 - N) << '\n';
  }
}
