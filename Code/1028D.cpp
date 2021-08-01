#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i] >> P[i];
  }
  set<int> A;
  set<int> B;
  set<int> wait;
  long long Ans = 1;
  for (int i = 0; i < N; ++i) {
    if (S[i] == "ADD") {
      if (!B.empty() && P[i] > *B.begin()) {
        B.insert(P[i]);
      } else if (!A.empty() && P[i] < *A.rbegin()) {
        A.insert(P[i]);
      } else {
        wait.insert(P[i]);
      }
    } else {
      if (wait.find(P[i]) != wait.end()) {
        wait.erase(P[i]); 
        while (!wait.empty()) {
          if (*wait.begin() < P[i]) {
            A.insert(*wait.begin());
          } else {
            B.insert(*wait.begin());
          }
          wait.erase(wait.begin());
        }
        if (!A.empty() && P[i] < *A.rbegin() && !B.empty() && P[i] > *B.begin()) {
          cout << 0 << '\n';
          exit(0);
        }
        Ans *= 2;
        Ans %= MOD;
      } else {
        while (!wait.empty()) {
          if (*wait.begin() < P[i]) {
            A.insert(*wait.begin());
          } else {
            B.insert(*wait.begin());
          }
          wait.erase(wait.begin());
        }
        if (A.find(P[i]) != A.end()) {
          if (P[i] != *A.rbegin()) {
            cout << 0 << '\n'; 
            exit(0);
          }
          A.erase(P[i]);
        }
        if (B.find(P[i]) != B.end()) {
          if (P[i] != *B.begin()) {
            cout << 0 << '\n';
            exit(0);
          }
          B.erase(P[i]);
        }
      }
    }
  }  
  Ans *= (wait.size() + 1);
  Ans %= MOD;
  cout << Ans << '\n';
}
