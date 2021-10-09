#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  vector<int> c(q + 1);
  vector<int> a(q + 1);
  vector<int> p(q + 1);
  vector<int> dep(q + 1);
  vector<bool> mark(q + 1);
  scanf("%d%d", &a[0], &c[0]);
  vector<vector<int>> jump(q + 1, vector<int> (21, -1));
  for (int i = 1; i <= q; ++i) {
    int opt;
    scanf("%d", &opt);
    auto up = [&] (int x, int d) -> int {
      for (int i = 20; i >= 0; --i) {
        if (d >> i & 1) {
          if (jump[x][i] == -1) {
            return -1;
          } 
          x = jump[x][i];
        }
      }
      return x;
    };
    if (opt == 1) {
      scanf("%d%d%d", &p[i], &a[i], &c[i]);
      jump[i][0] = p[i];
      dep[i] = dep[p[i]] + 1;
      for (int j = 0; j < 20; ++j) {
        if (jump[i][j] != -1) {
          jump[i][j + 1] = jump[jump[i][j]][j];
        } 
      } 
    }
    if (opt == 2) {
      int v, w;
      scanf("%d%d", &v, &w); 
      long long ans = 0;
      long long tot = 0;
      int x = v;
      for (int j = 20; j >= 0; --j) {
        if (jump[x][j] != -1 && !mark[jump[x][j]]) {
          x = jump[x][j];
        } 
      }
      int d = dep[v] - dep[x]; 
      while (w && d >= 0) {
        int mn = min(w, a[x]);
        a[x] -= mn;
        if (a[x] == 0) {
          mark[x] = true;
        }
        w -= mn;
        ans += 1ll * mn * c[x];
        tot += mn;
        d--;
        if (d < 0) {
          break;
        }
        x = up(v, d);
      }
      printf("%lld %lld\n", tot, ans);
      fflush(stdout);
    }
  }
}
