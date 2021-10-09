#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  string s;
  cin >> s;
  int m = s.size();
  vector<vector<int>> ch(m * 2 + 1, vector<int> (2, -1));
  for (int i = 1; i <= m; ++i) {
    if (i * 2 <= m * 2 + 1) {
      ch[i][0] = i * 2;
    }
    if (i * 2 + 1 <= m * 2 + 1) {
      ch[i][1] = i * 2 + 1;
    }
  }
  queue<int> que;
  que.push(1);
  int tot = m;
  vector<int> id(m * 2 + 1);
  vector<int> mp(m * 2 + 1);
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    id[x] = tot;
    mp[tot] = x;
    tot--;
    if (x * 2 + 1 <= m) {
      que.push(x * 2 + 1);
    }
    if (x * 2 <= m) {
      que.push(x * 2);
    }
  }
  vector<int> sz(m * 2 + 1);
  for (int i = m + 1; i <= m * 2 + 1; ++i) {
    sz[i] = 1;
  }
  vector<bool> up(m * 2 + 1);
  for (int i = 0; i < m; ++i) {
    int j = mp[i + 1];
    if (s[i] == '?') {
      sz[j] = sz[ch[j][0]] + sz[ch[j][1]];
      up[ch[j][0]] = up[ch[j][1]] = true;
    } else {
      sz[j] = sz[ch[j][s[i] - '0']];
      up[ch[j][s[i] - '0']] = true;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p;
    char c;
    cin >> p >> c;
    p--;
    int x = mp[p + 1];
    int lst = sz[x];
    int cur = 0; 
    if (c == '?') {
      cur = sz[ch[x][0]] + sz[ch[x][1]];
      up[ch[x][0]] = up[ch[x][1]] = true;
    } else {
      cur = sz[ch[x][c - '0']];
      up[ch[x][c - '0']] = true;
      up[ch[x][(c - '0') ^ 1]] = false;
    }
    int d = cur - lst;
    sz[x] += d;
    while (x > 1 && up[x]) {
      x = x / 2; 
      sz[x] += d;
    }
    s[p] = c;
    cout << sz[1] << '\n';
  }
}
