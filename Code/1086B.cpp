#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, S;
  cin >> N >> S;
  vector<vector<int>> adj(N);
  vector<int> d(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    d[X] ++;
    d[Y] ++;
  }
  int D = 0;
  for (int i = 0; i < N; ++i) {
    if (d[i] == 1) {
      D ++;
    }
  }
  cout << fixed << setprecision(15);
  cout << ((long double)S / (long double)D * 2.) << '\n';
  return 0;
}
