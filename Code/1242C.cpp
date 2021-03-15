#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int K;
  cin >> K;
  vector<vector<long long>> V(K);
  vector<int> N(K);
  vector<long long> Sum(K);
  map<long long, pair<int, int>> mp;
  long long S = 0;
  for (int i = 0; i < K; ++i) {
    cin >> N[i];
    V[i].resize(N[i]);
    for (int j = 0; j < N[i]; ++j) {
      cin >> V[i][j];
      S += V[i][j];
      mp[V[i][j]] = { i, j };
    }
    Sum[i] = accumulate(V[i].begin(), V[i].end(), 0LL);
  }
  if (S % K != 0) {
    cout << "No" << '\n';
    exit(0);
  }
  long long W = S / K;
  vector<vector<tuple<int, long long, int>>> P(1 << K);
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < N[i]; ++j) {
      bool ok = true;
      vector<pair<int, int>> que;
      vector<bool> vis(K);
      set<pair<int, int>> hav;
      que.emplace_back(i, j);
      hav.emplace(i, j);
      while (true) {
        auto [X, Y] = que.back();
        long long D = W - (Sum[X] - V[X][Y]);
        if (mp.find(D) == mp.end()) {
          ok = false;
          break;
        }
        auto [X0, Y0] = mp[D];
        if (hav.find({ X0, Y0 }) != hav.end()) {
          if (X0 == i && Y0 == j) {
            ok = true;
          } else {
            ok = false;
          }
          break;
        }
        if (vis[X0]) {
          ok = false;
          break;
        }
        vis[X0] = true;
        que.emplace_back(X0, Y0);
      }
      if (ok) {
        int S0 = 0;
        for (auto [A, B] : que) {
          S0 ^= 1 << A;
        }
        if (!P[S0].empty()) {
          continue;
        }
        for (int k = 0; k < que.size(); ++k) {
          auto [A, B] = que[k];
          auto [C, D] = que[(k + 1) % que.size()];
          P[S0].emplace_back(C, V[C][D], A);
        } 
      }
    }
  }
  for (int S0 = 0; S0 < 1 << K; ++S0) {
    if (P[S0].empty()) {
      for (int S1 = S0; S1 != 0; S1 = (S1 - 1) & S0) {
        if (!P[S1].empty() && !P[S0 ^ S1].empty()) {
          for (auto O : P[S1]) {
            P[S0].push_back(O);
          }
          for (auto O : P[S0 ^ S1]) {
            P[S0].push_back(O);
          }
          break;    
        } 
      }
    }
  }
  auto& vec = P.back();
  if (vec.empty()) {
    cout << "No" << '\n';
  } else {
    sort(vec.begin(), vec.end());
    cout << "Yes" << '\n';
    for (auto [A, B, C] : vec) {
      cout << B << ' ' << C + 1 << '\n';
    }
  }
  return 0;
}
