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
  vector<int> lp = GetPrime(1000005);
  int T;
  cin >> T;
  while (T --> 0) {
    int K;
    cin >> K;
    K += 2;
    set<int> S;
    while (K != 1) {
      S.insert(lp[K]);
      K /= lp[K];
    }
    if (S.find(2) != S.end()) {
      S.erase(2);
    }
    if (S.empty()) {
      cout << -1 << '\n';;
      continue;
    }
    vector<int> Ans;
    for (int i : S) {
      Ans.push_back(i);
    }
    for (int i = 0; i < Ans.size(); ++i) {
      cout << Ans[i] << " \n"[i + 1 == Ans.size()];
    }
  }
}
