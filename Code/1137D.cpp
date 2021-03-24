#include <bits/stdc++.h>
using namespace std;
int main() {
  auto Read = [&] () -> int {
    int N;
    cin >> N;
    string S;
    for (int i = 0; i < N; ++i) {
      cin >> S;
    }
    return N;
  };
  while (true) {
    cout << "next" << ' ' << 0 << ' ' << 1 << endl;
    Read();
    cout << "next" << ' ' << 0 << endl;
    if (Read() == 2) {
      break;
    }
  } 
  while (true) {
    cout << "next";
    for (int i = 0; i < 10; ++i) {
      cout << ' ' << i;
    }
    cout << endl;
    if (Read() == 1) {
      break;
    }
  }
  cout << "done" << endl;
}
