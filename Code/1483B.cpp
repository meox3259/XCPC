#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    set<int> S;
    for (int i = 0; i < N; ++i) {
      S.insert(i);
    }
    vector<int> Nxt(N);
    for (int i = 0; i < N; ++i) {
      Nxt[i] = (i + 1) % N;
    }
    multiset<pair<int, int>> P;
    for (int i = 0; i < N; ++i) {
      if (__gcd(A[i], A[(i + 1) % N]) == 1) {
        P.emplace(i, (i + 1) % N); 
      } 
    }
    vector<bool> del(N);
    vector<int> Ans;
    while (!P.empty()) {
      vector<pair<int, int>> st;
      while (!P.empty()) {
        auto [X, Y] = *P.begin();
        P.erase(P.begin());
        del[Y] = true;
        Ans.push_back(Y);
        if (__gcd(A[Y], A[Nxt[Y]]) == 1 && P.find(make_pair(Y, Nxt[Y])) != P.end()) {
          P.erase(P.find(make_pair(Y, Nxt[Y])));
        }
        if (__gcd(A[X], A[Nxt[Y]]) == 1) {
          st.emplace_back(X, Nxt[Y]);
        }
        Nxt[X] = Nxt[Y];
      } 
      for (auto [X, Y] : st) {
        if (!del[X] && !del[Y]) {
          P.emplace(X, Y);
        }
      }
    }
    cout << Ans.size();
    for (int i : Ans) {
      cout << ' ' << i + 1;
    }
    cout << '\n';
  }
}
