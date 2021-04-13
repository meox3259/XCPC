#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(M);
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }
  multiset<int> S;
  for (int i : B) {
    S.insert(i);
  }
  sort(A.begin(), A.end());
  int Ans = 0;
  while (!A.empty()) {
    int V = A.back();
    A.pop_back();
    if (S.find(V) != S.end()) {
      S.erase(S.find(V));
    } else {
      Ans += *S.begin();
      Ans -= V;
      S.erase(S.begin());
    }
  } 
  for (int i : S) {
    Ans += i;
  }
  cout << Ans << '\n';
}
