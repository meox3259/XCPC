#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> k(n);
  vector<int> al(n);
  vector<int> bl(n);
  vector<int> ar(n);
  vector<int> br(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i] >> al[i] >> bl[i] >> ar[i] >> br[i];
  }
  vector<int> cl(n + 1);
  vector<int> dl(n + 1);
  vector<int> cr(n + 1);
  vector<int> dr(n + 1);
  cl[n] = 0;
  dl[n] = m;
  cr[n] = 0;
  dr[n] = m;
  for (int i = n - 1; i >= 0; --i) {
    cl[i] = m;
    dl[i] = 0;
    cr[i] = m;
    dr[i] = 0;
    if (al[i] <= k[i] && k[i] <= bl[i]) {
      if (cl[i + 1] <= k[i] && k[i] <= dl[i + 1]) {
        cr[i] = ar[i];
        dr[i] = br[i];
      } else {
        cr[i] = max(cr[i + 1], ar[i]);
        dr[i] = min(dr[i + 1], br[i]);
      }
    }
    if (ar[i] <= k[i] && k[i] <= br[i]) {
      if (cr[i + 1] <= k[i] && k[i] <= dr[i + 1]) {
        cl[i] = al[i];
        dl[i] = bl[i];
      } else {
        cl[i] = max(cl[i + 1], al[i]);
        dl[i] = min(dl[i + 1], bl[i]);
      }
    }
  }
  if ((cl[0] <= 0 && 0 <= dl[0]) || (cr[0] <= 0 && 0 <= dr[0])) {
    cout << "Yes" << '\n'; 
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
      if (cl[i] <= x && x <= dl[i]) {
        y = k[i];
        cout << 1 << " \n"[i == n - 1];
      } else if (cr[i] <= y && y <= dr[i]) {
        x = k[i];
        cout << 0 << " \n"[i == n - 1];
      }
    }
  } else {
    cout << "No" << '\n';
  }
}
