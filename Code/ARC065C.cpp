#include <bits/stdc++.h>
using namespace std;
#define ALL(A) A.begin(), A.end()
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, A, B;
  cin >> N >> A >> B;
  A --;
  B --;
  vector<long long> X(N);
  vector<long long> Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  vector<long long> SX;
  for (int i = 0; i < N; ++i) {
    SX.push_back(X[i] - Y[i]);
  }
  sort(ALL(SX));
  SX.erase(unique(ALL(SX)), SX.end());
  auto idX = [&] (long long X) -> int {
    if (!binary_search(ALL(SX), X)) {
      return -1;
    }
    return lower_bound(ALL(SX), X) - SX.begin();
  };
  vector<vector<long long>> PX(SX.size());
  vector<set<pair<long long, int>>> adjX(SX.size());
  for (int i = 0; i < N; ++i) {
    PX[idX(X[i] - Y[i])].push_back(Y[i]);
    adjX[idX(X[i] - Y[i])].emplace(Y[i], i);
  }
  for(auto& vec : PX) {
    sort(ALL(vec));
  }
  vector<long long> SY;
  for (int i = 0; i < N; ++i) {
    SY.push_back(X[i] + Y[i]);
  }
  sort(ALL(SY));
  SY.erase(unique(ALL(SY)), SY.end());
  auto idY = [&] (long long Y) -> int {
    if (!binary_search(ALL(SY), Y)) {
      return -1;
    }
    return lower_bound(ALL(SY), Y) - SY.begin();
  };
  vector<vector<long long>> PY(SY.size()); 
  vector<set<pair<long long, int>>> adjY(SY.size());
  for (int i = 0; i < N; ++i) {
    PY[idY(X[i] + Y[i])].push_back(Y[i]);
    adjY[idY(X[i] + Y[i])].emplace(Y[i], i);
  }
  for (auto& vec : PY) {
    sort(ALL(vec));
  }
  long long D = abs(X[A] - X[B]) + abs(Y[A] - Y[B]);
  vector<bool> vis(N);
  vector<int> node;
  queue<int> Q;
  Q.push(A);
  Q.push(B);
  while (!Q.empty()) {
    int i = Q.front();
    Q.pop();
    if (vis[i]) {
      continue;
    }
    node.push_back(i);
    vis[i] = true;
    int p1 = idX(X[i] - Y[i] + D);
    if (p1 != -1) {
      vector<pair<long long, int>> tmp;
      for (auto it = adjX[p1].lower_bound(make_pair(Y[i] - D, -1)); it != adjX[p1].end() && it -> first <= Y[i]; ++it) {
        tmp.push_back(*it);    
        if (!vis[it -> second]) {
          Q.push(it -> second);
        }
      }
      for (auto o : tmp) {
        adjX[p1].erase(o);
      }
    }
    int p2 = idX(X[i] - Y[i] - D);
    if (p2 != -1) {
      vector<pair<long long, int>> tmp;
      for (auto it = adjX[p2].lower_bound(make_pair(Y[i], -1)); it != adjX[p2].end() && it -> first <= Y[i] + D; ++it) {
        tmp.push_back(*it);
        if (!vis[it -> second]) {
          Q.push(it -> second);
        }
      }
      for (auto o : tmp) {
        adjX[p2].erase(o);
      }
    }
    int p3 = idY(X[i] + Y[i] - D);
    if (p3 != -1) {
      vector<pair<long long, int>> tmp;
      for (auto it = adjY[p3].lower_bound(make_pair(Y[i] - D, -1)); it != adjY[p3].end() && it -> first <= Y[i]; ++it) {
        tmp.push_back(*it);
        if (!vis[it -> second]) {
          Q.push(it -> second);
        }
      }
      for (auto o : tmp) {
        adjY[p3].erase(o);
      }
    }
    int p4 = idY(X[i] + Y[i] + D);
    if (p4 != -1) {
      vector<pair<long long, int>> tmp;
      for (auto it = adjY[p4].lower_bound(make_pair(Y[i], -1)); it != adjY[p4].end() && it -> first <= Y[i] + D; ++it) {
        tmp.push_back(*it);
        if (!vis[it -> second]) {
          Q.push(it -> second);
        }
      }
      for (auto o : tmp) {
        adjY[p4].erase(o);
      }
    }
  }
  long long ans = 0;
  for (int i : node) {
    int p1 = idX(X[i] - Y[i] + D);     
    int p2 = idX(X[i] - Y[i] - D);
    int p3 = idY(X[i] + Y[i] - D);
    int p4 = idY(X[i] + Y[i] + D);
    int last = ans;
    if (p1 != -1) {
      ans += upper_bound(ALL(PX[p1]), Y[i] - 1) - lower_bound(ALL(PX[p1]), Y[i] - D);
    }
    if (p2 != -1) {
      ans += upper_bound(ALL(PX[p2]), Y[i] + D - 1) - lower_bound(ALL(PX[p2]), Y[i]);
    }
    if (p3 != -1) {
      ans += upper_bound(ALL(PY[p3]), Y[i] - 1) - lower_bound(ALL(PY[p3]), Y[i] - D);
    }
    if (p4 != -1) {
      ans += upper_bound(ALL(PY[p4]), Y[i] + D - 1) - lower_bound(ALL(PY[p4]), Y[i]);
    }
  }
  ans /= 2;
  cout << ans << '\n';
  return 0;
}
