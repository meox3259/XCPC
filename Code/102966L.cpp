#include <bits/stdc++.h>
using namespace std;
vector<int> GetPrime(int n) {
    vector<bool> mark(n + 1);
    vector<int> Prime;
    vector<int> lp(n + 1);
    iota(lp.begin(), lp.end(), 0);
    for (int i = 2; i <= n; ++i) {
        if (!mark[i]) {
            Prime.emplace_back(i);
            lp[i] = i;
        }
        for (int j = 0; j < Prime.size() && i * Prime[j] <= n; ++j) {
            mark[i * Prime[j]] = true;
            lp[i * Prime[j]] = min(lp[i * Prime[j]], Prime[j]);
            lp[i * Prime[j]] = min(lp[i * Prime[j]], lp[i]);
            if (i % Prime[j] == 0) {
                break;
            }
        }
    }
    return lp;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> lp = GetPrime(10000000);
  int T;
  cin >> T;
  while (T --> 0) {
    int A, B;
    cin >> A >> B;
    vector<int> P;
    while (A != 1) {
      P.push_back(lp[A]);
      A /= lp[A];
    }
    while (B != 1) {
      P.push_back(lp[B]);
      B /= lp[B];
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    cout << P.size() << '\n';
  }
}
