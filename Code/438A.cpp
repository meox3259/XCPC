#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> V(N);
  for (int i = 0; i < N; ++i) {
    cin >> V[i];
  }
  long long Ans = 0;
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    Ans += min(V[X], V[Y]);
  }
  cout << Ans << '\n';
}
