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
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }
    vector<int> CA(101);
    for (int i : A) {
      CA[i] ++;
    }
    vector<int> CB(101);
    for (int i : B) {
      CB[i] ++;
    }
    int L = -1;
    int R = N + 1;
    while (R - L > 1) {
      int Mid = L + R >> 1;
      CA[100] += Mid;
      CB[0] += Mid;
      int KA = (N + Mid) - (N + Mid) / 4;
      int KB = (N + Mid) - (N + Mid) / 4;
      int SA = 0;
      int SB = 0;
      for (int i = 100; i >= 0; --i) {
        SA += min(CA[i], KA) * i;
        SB += min(CB[i], KB) * i;
        KA -= min(CA[i], KA);
        KB -= min(CB[i], KB);
      }
      if (SA >= SB) {
        R = Mid;
      } else {
        L = Mid;
      }
      CA[100] -= Mid;
      CB[0] -= Mid;
    }
    cout << R << '\n';
  }
}
