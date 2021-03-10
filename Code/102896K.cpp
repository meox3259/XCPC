#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int ans = -1;
  int Min = numeric_limits<int> :: max();
  for (int i = 0; i < N; ++i) {
    int P;
    string S;
    cin >> P >> S;
    vector<int> cnt(10);
    for (char c : S) {
      cnt[c - '0'] ++; 
    }
    if (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 2) {
      if (P < Min) {
        Min = P;
        ans = i;
      } 
    }
  }
  cout << ans + 1 << '\n';
  return 0;
}
