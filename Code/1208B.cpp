#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  unordered_map<int, int> cnt;
  for (int i : A) {
    cnt[i] ++;
  }
  multiset<int> S;
  for (auto o : cnt) {
    S.insert(o.second);
  }
  if (*S.rbegin() <= 1) {
    cout << 0 << '\n';
    exit(0);
  }
  int ans = N;
  for (int i = 0; i < N; ++i) {
    auto tmp = cnt;
    auto T = S;
    for (int j = i; j < N; ++j) {
      T.erase(T.find(tmp[A[j]]));
      tmp[A[j]] --;
      T.insert(tmp[A[j]]);
      if (*T.rbegin() <= 1) {
        ans = min(ans, j - i + 1);
        break;
      }
    } 
  }
  cout << ans << '\n';
  return 0;
}
