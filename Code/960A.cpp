#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  vector<int> A;
  vector<int> B;
  vector<int> C;
  int N = S.size();
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'a') {
      A.push_back(i);
    }
    if (S[i] == 'b') {
      B.push_back(i);
    }
    if (S[i] == 'c') {
      C.push_back(i);
    }
  }
  if (A.empty() || B.empty()) {
    cout << "NO" << '\n';
    exit(0);
  }
  if (C.size() != A.size() && C.size() != B.size()) {
    cout << "NO" << '\n';
    exit(0);
  }
  if (A.back() + 1 != A.size()) {
    cout << "NO" << '\n';
    exit(0);
  }
  if (B.back() + 1 != A.size() + B.size()) {
    cout << "NO" << '\n';
    exit(0);
  }
  cout << "YES" << '\n';
}
