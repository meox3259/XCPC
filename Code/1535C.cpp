#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    vector<vector<int>> cnt(2, vector<int> (2));
    for (int i = 0, j = 0; i < n; ++i) {
      if (s[i] != '?') {
        cnt[s[i] - '0'][i & 1]++;
      }
      while (j <= i && ((cnt[0][0] > 0 && cnt[0][1] > 0) || (cnt[1][0] > 0 && cnt[1][1] > 0) || (cnt[0][0] > 0 && cnt[1][0] > 0) || (cnt[0][1] > 0 && cnt[1][1] > 0))) {
        if (s[j] != '?') {
          cnt[s[j] - '0'][j & 1]--; 
        }
        j++;
      }
      ans += i - j + 1;
    }
    cout << ans << '\n';
  }
}
