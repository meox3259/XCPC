#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 5;
const long long M = 5e18;
long long exgcd(long long a, long long b, long long &X, long long &Y) {
  if (b == 0) {
    X = 1;
    Y = 0;
    return a;
  }
  long long ret = exgcd(b, a % b, X, Y);
  long long tmp = X;
  X = Y;
  Y = tmp - (a / b) * Y;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  random_device rnd;
  mt19937 mt(rnd());
  long long x;
  cin >> x;
  unordered_set<long long> S;
  vector<long long> A;
  vector<tuple<long long, char, long long> > ans;
  for (long long i = 0; i < 20; ++i) {
    assert((x << (i + 1)) <= M);
    ans.emplace_back(x << i, '+', x << i);
    S.insert(x << i);
    A.push_back(x << i);
  }
  while (true) {
    auto check = [&] (long long X, long long Y) -> bool {
      long long A, B;  
      long long g = exgcd(X, Y, A, B);
      if (g > 1) {
        return false;
      }
      A = (A % Y + Y) % Y;
      B = (A * X - 1) / Y;
      if (A * X > M || B * Y > M) {
        return false;
      }
      if ((A * X) & 1) {
        long long SA = 0;
        for (long long i = 0; i < 62; ++i) {
          if (A >> i & 1) {
            if (SA != 0) {
              assert((SA + (X << i)) <= M);
              ans.emplace_back(SA, '+', X << i); 
            }
            SA += X << i;
          }
          if (SA == A * X) {
            break;
          }
          assert((X << (i + 1)) <= M);
          ans.emplace_back(X << i, '+', X << i);
        }
        long long SB = 0;
        for (long long i = 0; i < 62; ++i) {
          if (B >> i & 1) {
            if (SB != 0) {
              assert((SB + (Y << i)) <= M);
              ans.emplace_back(SB, '+', Y << i);
            }
            SB += Y << i;
          }
          if (SB == B * Y) {
            break;
          }
          assert((Y << (i + 1)) <= M);
          ans.emplace_back(Y << i, '+', Y << i);
        }
        ans.emplace_back(SA, '^', SB);
        return true;
      } 
      return false;
    };
    if (mt() & 1) { // 挑最小的加进去
      long long Min = Inf;
      long long X = -1;
      long long Y = -1;
      int w = -1;
      for (auto i : S) {
        for (auto j : S) {
          if (i != j && (i ^ j) < Min && S.find(i ^ j) == S.end()) {
            Min = i ^ j;
            X = i;
            Y = j;
            w = 0;
          }
          if (i + j < Min && S.find(i + j) == S.end()) {
            Min = i + j;
            X = i;
            Y = j;
            w = 1;
          }
        }
      }
      if (w == -1) {
        continue;
      }
      if (w == 0) {
        assert((X ^ Y) <= M);
        ans.emplace_back(X, '^', Y);
      } 
      if (w == 1) {
        assert(X + Y <= M);
        ans.emplace_back(X, '+', Y);
      }
      S.insert(Min);
      A.push_back(Min);
      for (auto i : S) {
        if (check(i, Min) || check(Min, i)) {
          cout << ans.size() << '\n';
          for (auto [X, c, Y] : ans) {
            cout << X << ' ' << c << ' ' << Y << '\n';
          }
          exit(0);
        }
      }
    } else {
      random_shuffle(A.begin(), A.end());
      long long Min = Inf;
      long long X = -1;
      long long Y = -1;
      int w = -1;
      for (auto i : A) {
        for (auto j : A) {
          if (i != j && S.find(i ^ j) == S.end()) {
            Min = i ^ j; 
            X = i;
            Y = j;
            w = 0;
            break;
          } 
          if (S.find(i + j) == S.end()) {
            Min = i + j;
            X = i;
            Y = j;
            w = 1;
            break;
          }
        }
        if (w != -1) {
          break;
        }
      }
      if (w == -1) {
        continue;
      }
      if (w == 0) {
        assert((X ^ Y) <= M);
        ans.emplace_back(X, '^', Y);
      }
      if (w == 1) {
        assert(X + Y <= M);
        ans.emplace_back(X, '+', Y);
      }
      S.insert(Min);
      A.push_back(Min);
      for (auto i : S) {
        if (check(i, Min) || check(Min, i)) {
          cout << ans.size() << '\n';
          for (auto [X, c, Y] : ans) {
            cout << X << ' ' << c << ' ' << Y << '\n';
          }
          exit(0);
        }
      }
    }
  }
  return 0;
}
