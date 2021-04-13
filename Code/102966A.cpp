#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  cout << (1LL << M) + (1LL << N) - 2 << '\n';
}
