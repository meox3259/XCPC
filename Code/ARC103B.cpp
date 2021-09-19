#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> x(n);
  vector<long long> y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i < n; ++i) {
    if (abs(x[0] + y[0]) % 2 != abs(x[i] + y[i]) % 2) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  vector<long long> f;
  for (int i = 0; i < 31; ++i) {
    f.push_back(1 << i);
  }
  if (abs(x[0] + y[0]) % 2 == 0) {
    f.push_back(1);
  }
  sort(f.begin(), f.end(), greater<long long> ());
  int m = f.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << f[i] << " \n"[i == m - 1];
  }
  for (int i = 0; i < n; ++i) {
    x[i] = -x[i];
    y[i] = -y[i];
    for (int j = 0; j < m; ++j) {
      if (abs(x[i]) > abs(y[i])) {
        if (x[i] < 0) {
          x[i] += f[j];
          cout << 'R';
        } else {
          x[i] -= f[j];
          cout << 'L';
        }
      } else {
        if (y[i] < 0) {
          y[i] += f[j];
          cout << 'U';
        } else {
          y[i] -= f[j];
          cout << 'D';
        }
      } 
    } 
    cout << '\n';
  }
}
