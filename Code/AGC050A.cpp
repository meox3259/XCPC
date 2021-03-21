#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cout << (i * 2 + 1) % N + 1 << ' ' << (i * 2 + 2) % N + 1 << '\n'; 
  }
}
