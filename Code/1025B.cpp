#include <bits/stdc++.h>
using namespace std;
vector<int> GetPrime(int n) {
  vector<bool> mark(n + 1);
  vector<int> Prime;
  for (int i = 2; i <= n; ++i) {
    if (!mark[i]) {
      Prime.emplace_back(i);
    }
    for (int j = 0; j < Prime.size() && i * Prime[j] <= n; ++j) {
      mark[i * Prime[j]] = true;
      if (i % Prime[j] == 0) {
        break;
      }
    }
  }
  return Prime;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> P = GetPrime(100000);
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i]; 
  }
  long long g = 0;
  for (int i = 0; i < N; ++i) {
    long long C = A[i] / __gcd(A[i], B[i]) * B[i];
    g = __gcd(g, C);
  }
  for (int i : P) {
    if (g % i == 0) {
      cout << i << '\n';
      exit(0);
    }
  }
  vector<long long> ALL;
  for (auto i : A) {
    ALL.push_back(i);
  }
  for (auto i : B) {
    ALL.push_back(i);
  }
  for (auto i : ALL) {
    if (__gcd(i, g) >= 2) {
      cout << __gcd(i, g) << '\n';
      exit(0);
    }
  }
  cout << -1 << '\n';
}
