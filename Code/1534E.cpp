#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  auto query = [&] (vector<int> idx) -> int {
    cout << '?';
    for (int i = 0; i < K; ++i) {
      cout << ' ' << idx[i] + 1;
    }
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  if (N == K) {
    vector<int> A(N);
    iota(A.begin(), A.end(), 0);
    int Ans = query(A);
    cout << '!' << ' ' << Ans << endl;
    exit(0);
  }
  if (K % 2 == 0 && N % 2 == 1) {
    cout << -1 << endl;
  } else if (K % 2 == 0 && N % 2 == 0) {
    int Ans = 0;
    int L = min(K * 2, (N - K) * 2);
    for (int i = 0; i < (N - L + K - 1) / K; ++i) {
      vector<int> A; 
      for (int j = 0; j < K; ++j) {
        A.push_back(i * K + j);
      }
      Ans ^= query(A);
    }
    int Need = N - (N - L + K - 1) / K * K;
    int P = N - Need;
    while (Need > 0) {
      int D = min(min(Need, K * 2), (N - K) * 2);
      vector<int> B;
      vector<int> C;
      for (int i = 0; i < D / 2; ++i) {
        B.push_back(P + i);
        C.push_back(P + D / 2 + i);
      }
      for(int i = 0; i < N && B.size() < K && C.size() < K; ++i) {
        if (!(P <= i && i < P + D)) {
          B.push_back(i);
          C.push_back(i);
        }
      }
      Ans ^= query(B) ^ query(C);
      Need -= D;
      P += D;
    }
    cout << '!' << ' ' << Ans << endl;
  } else if (K % 2 == 1 && N % 2 == 1) {
    int Ans = 0;
    vector<int> A;
    for (int i = 0; i < K; ++i) {
      A.push_back(i);
    }
    Ans ^= query(A);
    int Need = N - K;
    int P = K;
    while (Need > 0) {
      int D = min(min(Need, 2 * K), (N - K) * 2);
      vector<int> B;
      vector<int> C;
      for (int i = 0; i < D / 2; ++i) {
        B.push_back(P + i);
        C.push_back(P + D / 2 + i);
      }
      for(int i = 0; i < N && B.size() < K && C.size() < K; ++i) {
        if (!(P <= i && i < P + D)) {
          B.push_back(i);
          C.push_back(i);
        }
      }
      Ans ^= query(B) ^ query(C);
      Need -= D;
      P += D;
    }
    cout << '!' << ' ' << Ans << endl;
  } else if (K % 2 == 1 && N % 2 == 0) {
    int Ans = 0;
    int Need = N;
    int P = 0;
    while (Need > 0) {
      int D = min(min(Need, 2 * K), (N - K) * 2);
      vector<int> B;
      vector<int> C;
      for (int i = 0; i < D / 2; ++i) {
        B.push_back(P + i);
        C.push_back(P + D / 2 + i);
      }
      for(int i = 0; i < N && B.size() < K && C.size() < K; ++i) {
        if (!(P <= i && i < P + D)) {
          B.push_back(i);
          C.push_back(i);
        }
      }
      Ans ^= query(B) ^ query(C);
      Need -= D;
      P += D;
    }
    cout << '!' << ' ' << Ans << endl;
  }
}
