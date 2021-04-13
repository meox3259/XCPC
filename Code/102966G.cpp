#include <bits/stdc++.h>
using namespace std;
int main() {
  long long L;
  int G;
  cin >> L >> G;
  vector<long long> p(G);
  vector<int> d(G);
  for (int i = 0; i < G; ++i) {
    cin >> p[i] >> d[i];
  }
  long long Ans = 0;
  for (int i = 0; i < G; ++i) {
    if (d[i] == 0) {
      Ans = max(Ans, p[i]);
    } else {
      Ans = max(Ans, L - p[i]);
    }
  }
  cout << Ans << '\n';
}
