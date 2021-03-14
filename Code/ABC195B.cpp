#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 10;
int main() {
  long long A, B, W;
  cin >> A >> B >> W;
  long long Min = Inf;
  long long Max = -Inf;
  bool ok = false;
  for (int i = 1; i <= W * 1000; ++i) {
    if (A * i <= W * 1000 && B * i >= W * 1000) {
      Min = min(Min, 1LL * i);
      Max = max(Max, 1LL * i);
      ok = true;
    }
  }
  if (!ok) {
    cout << "UNSATISFIABLE" << '\n';
  } else {
    cout << Min << ' ' << Max << '\n';
  }
  return 0;
}
