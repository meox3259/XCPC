#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> P(N);
  vector<char> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i] >> C[i];
  }
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    mp[P[i]] = i;
  }
  vector<int> id;
  for (int i = 0; i < N; ++i) {
    if (C[i] == 'P') {
      id.push_back(i);
    }
  }
  long long Ans = 0;
  for (int i = 0; i + 1 < id.size(); ++i) {
    vector<int> B{id[i]};
    vector<int> R{id[i]};
    for (int j = id[i] + 1; j < id[i + 1]; ++j) {
      if (C[j] == 'B') {
        B.push_back(j);
      }
      if (C[j] == 'R') {
        R.push_back(j);
      }
    } 
    B.push_back(id[i + 1]);
    R.push_back(id[i + 1]);
    long long len = P[id[i + 1]] - P[id[i]];
    long long MaxB = 0;
    long long MaxR = 0;
    for (int j = 0; j + 1 < B.size(); ++j) {
      MaxB = max(MaxB, P[B[j + 1]] - P[B[j]]);
    }
    for (int j = 0; j + 1 < R.size(); ++j) {
      MaxR = max(MaxR, P[R[j + 1]] - P[R[j]]);
    }
    Ans += min((P[id[i + 1]] - P[id[i]]) * 2, (P[id[i + 1]] - P[id[i]]) * 3 - MaxB - MaxR);
  }
  vector<int> B;
  for (int i = 0; i < N; ++i) {
    if (C[i] == 'B') {
      B.push_back(i);
    }
  }
  vector<int> R;
  for (int i = 0; i < N; ++i) {
    if (C[i] == 'R') {
      R.push_back(i);
    }
  }
  if (id.empty()) {
    if (!B.empty()) {
      Ans += P[B.back()] - P[B[0]];
    } 
    if (!R.empty()) {
      Ans += P[R.back()] - P[R[0]];
    }
  } else {
    if (!B.empty()) {
      Ans += max(0LL, P[id[0]] - P[B[0]]);
      Ans += max(0LL, P[B.back()] - P[id.back()]);
    }
    if (!R.empty()) {
      Ans += max(0LL, P[id[0]] - P[R[0]]);
      Ans += max(0LL, P[R.back()] - P[id.back()]);
    }
  }
  cout << Ans << '\n';
}
