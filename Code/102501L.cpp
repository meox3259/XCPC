#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<bool>> vis(n, vector<bool> (n));
  vector<vector<int>> id(n, vector<int> (n));
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '*' && !vis[i][j]) {
        queue<int> q;
        q.push(i);
        q.push(j);
        tot++;
        while (!q.empty()) {
          int x = q.front();
          q.pop();
          int y = q.front();
          q.pop();
          vis[x][y] = true;
          id[x][y] = tot;
          for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (0 <= xx && xx < n && 0 <= yy && yy < n && s[xx][yy] == '*' && !vis[xx][yy]) {
              q.push(xx);
              q.push(yy);
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vis[i][j]) {
        for (int k = 0; k < 4; ++k) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (0 <= x && x < n && 0 <= y && y < n && s[x][y] == '.') {
            id[x][y] = id[i][j];
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!vis[i][j] && id[i][j] && s[i][j] == '.') {
        vector<pair<int, int>> q;
        q.emplace_back(i, j);
        vis[i][j] = true;
        for (int i = 0; i < q.size(); ++i) {
          auto [x, y] = q[i];
          for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (0 <= xx && xx < n && 0 <= yy && yy < n && id[xx][yy] == id[x][y] && !vis[xx][yy]) {
              vis[xx][yy] = true;
              q.emplace_back(xx, yy);
            }
          }
        }
        int m = q.size();
        vector<int> adj(m);
        for (int x = 0; x < m; ++x) {
          for (int y = 0; y < m; ++y) {
            if (abs(q[x].first - q[y].first) + abs(q[x].second - q[y].second) <= 1) {
              adj[x] |= 1 << y;
            }
          }
        }
        vector<int> sg(1 << m);
        for (int s = 0; s < 1 << m; ++s) {
          vector<int> c(m + 2); 
          for (int k = 0; k < m; ++k) {
            if (s >> k & 1) {
              c[sg[s & ~adj[k]]]++;
            }
          }
          while (c[sg[s]]) {
            sg[s]++;
          }
        }
        ans ^= sg.back();
      }
    }
  }
  if (ans) {
    cout << "First player will win\n";
  } else {
    cout << "Second player will win\n";
  }
}
