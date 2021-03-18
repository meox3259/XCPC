#include <bits/stdc++.h>
using namespace std;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum += v[i - 1];
    }
    return sum;
  }
  T range(int l, int r) {
    return query(r) - query(l - 1);
  }
};
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
  vector<int> Pri = GetPrime(10000000);
  int T;
  cin >> T;
  while (T --) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    map<vector<int>, int> mp;
    vector<int> P(N);
    int Ans = 0;
    int tot = 0;
    for (int i = 0; i < N; ++i) {
      vector<int> F;
      for (int j : Pri) {
        if (j * j > A[i]) {
          break;
        }
        if (A[i] % j == 0) {
          int W = 0;
          while (A[i] % j == 0) {
            A[i] /= j;
            W ^= 1;
          }
          if (W == 1) {
            F.push_back(j);
          }
        }
      }  
      if (A[i] > 1) {
        F.push_back(A[i]);
      }
      sort(F.begin(), F.end());
      if (mp.find(F) == mp.end()) {
        mp[F] = tot ++;
      }
      P[i] = mp[F];
    } 
    vector<vector<int>> dp(N + 1, vector<int> (K + 1, N));
    dp[0][0] = 0;
    vector<int> last(tot, -1);
    FenwickTree<int> fw(N);
    for (int i = 0; i < N; ++i) {
      if (last[P[i]] != -1) {
        fw.add(last[P[i]], 1);
      } 
      last[P[i]] = i;
      for (int j = 0; j <= K; ++j) {
        int L = -1;
        int R = i;
        while (R - L > 1) {
          int mid = L + R >> 1;
          if (fw.range(mid, i) > j) {
            L = mid;
          } else {
            R = mid;
          }
        }
        for (int k = j; k <= K; ++k) {
          dp[i + 1][k] = min(dp[i + 1][k], dp[R][k - j] + 1);
        }
      }
    }
    cout << *min_element(dp[N].begin(), dp[N].end()) << '\n';
  }
  return 0;
}
