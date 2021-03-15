#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
} 
namespace IO 
{
    inline void read(int &x)
    {
        x = 0;
        int f = 1; char c = getchar();
        while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
        while(c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + c - '0'; c = getchar(); }
        x *= f;
    }
    inline void readl(long long &x)
    {
        x = 0;
        long long f = 1; char c = getchar();
        while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
        while(c >= '0' && c <= '9') { x = (x << 1ll) + (x << 3ll) + c - '0'; c = getchar(); }
        x *= f;
    } 
} using namespace IO;
int main() {
  int n, m;
  long long k;
  read(n);
  read(m);
  readl(k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    read(a[i]);
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    read(b[i]);
  }
  if (n > m) {
    swap(n, m);
    swap(a, b);
  }
  int M = 2 * max(n, m) + 1;
  vector<int> pa(M, -1);
  for (int i = 0; i < n; ++i) {
    pa[a[i]] = i;
  }
  vector<int> pb(M, -1);
  for (int i = 0; i < m; ++i) {
    pb[b[i]] = i;
  }
  vector<long long> mn(m, 1e18);
  vector<bool> vis(m);
  long long cur = n % m;
  int step = 0;
  while (!vis[cur]) {
    step ++;
    mn[cur] = step;
    vis[cur] = true;
    cur = (cur + n) % m;
  }
  long long l = 0;
  long long r = 1e18 + 5;
  auto check = [&] (long long tot) -> bool {
    long long ret = tot;
    for (int i = 0; i < n; ++i) {
      if (ret < k) {
        return false;
      }
      int x = i;     
      int y = pb[a[i]];
      if (y == -1) {
        continue;
      }
      int d = (y + m - x) % m;
      if (!vis[d]) {
        continue;
      }
      if (x == y) {
        if (tot >= x + 1) {
          ret --;
          ret -= (tot - x - 1) / (mn[0] * n);
        }
      } else {
        if (i + 1 + mn[d] * n <= tot) {
          ret --;
          ret -= (tot - mn[d] * n - i - 1) / (mn[0] * n);
        }
      }
    }
    return ret >= k;
  };
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << '\n';
  return 0;
}
