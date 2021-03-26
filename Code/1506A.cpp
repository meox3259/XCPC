#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    long long N, M, X;
    cin >> N >> M >> X;
    X --;
    long long A = X % N;
    long long B = X / N;
    cout << A * M + B + 1 << '\n';
  }
}
