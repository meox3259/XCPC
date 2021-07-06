#include <bits/stdc++.h>
using namespace std;
struct sgt {
  vector<long long> sum;
  vector<int> sz;
  vector<int> lc;
  vector<int> rc;
  vector<long long> Val;
  int Pool;
  sgt() {}
  sgt(int N) : sum(N * 62 + 5), sz(N * 62 + 5), lc(N * 62 + 5), rc(N * 62 + 5), Val(N) { Pool = 0; }
  void update(int L, int R, int &X, int Y, int P, long long V) {
    X = ++Pool;
    lc[X] = lc[Y];
    rc[X] = rc[Y];
    sz[X] = sz[Y] + 1;
    sum[X] = sum[Y] + V;
    if (L == R) {
      Val[L] = V;
      return;
    }
    int Mid = (L + R) / 2;
    if (P <= Mid) {
      update(L, Mid, lc[X], lc[Y], P, V); 
    } else {
      update(Mid + 1, R, rc[X], rc[Y], P, V);
    }
  } 
  long long query(int L, int R, int X, int K) {
    if (L == R) {
      return 1LL * K * Val[L];
    }
    int Mid = (L + R) / 2;
    if (sz[rc[X]] >= K) {
      return query(Mid + 1, R, rc[X], K);
    } else {
      return sum[rc[X]] + query(L, Mid, lc[X], K - sz[rc[X]]);
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> M(N);
  for (int i = 0; i < N; ++i) {
    cin >> M[i];
  }
  vector<long long> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  vector<int> id(N);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&] (int i, int j) -> bool {
    return P[i] == P[j] ? M[i] < M[j] : P[i] < P[j];
  });
  vector<long long> pre(N + 1);
  for (int i = 0; i < N; ++i) {
    pre[i + 1] = pre[i] + P[id[i]];
  }
  vector<int> r1(N + 1);
  vector<int> r2(N + 2);
  vector<long long> sp1;
  for (int i = 0; i < N; ++i) {
    sp1.push_back(M[i] + P[i]);
  }
  sort(sp1.begin(), sp1.end());
  sp1.erase(unique(sp1.begin(), sp1.end()), sp1.end());
  vector<long long> sp2;
  for (int i = 0; i < N; ++i) {
    sp2.push_back(M[i]);
  }
  sort(sp2.begin(), sp2.end());
  sp2.erase(unique(sp2.begin(), sp2.end()), sp2.end());
  sgt t1(N);
  sgt t2(N);
  for (int i = 1; i <= N; ++i) {
    t1.update(0, (int)sp1.size() - 1, r1[i], r1[i - 1],
    lower_bound(sp1.begin(), sp1.end(), P[id[i - 1]] + M[id[i - 1]]) - sp1.begin(), P[id[i - 1]] + M[id[i - 1]]); 
  }
  for (int i = 1; i <= N; ++i) {
    t2.update(0, (int)sp2.size() - 1, r2[i], r2[i - 1], 
    lower_bound(sp2.begin(), sp2.end(), M[id[N - i]]) - sp2.begin(), M[id[N - i]]);
  }
  int Ans = 0;
  for (int A = 1; A <= N / 2; ++A) {
    int L = 0;
    int R = A;
    auto calc = [&] (int D) -> long long {
      long long ret = -pre[D + A]; 
      ret += t1.query(0, (int)sp1.size() - 1, r1[D + A], D);
      ret += t2.query(0, (int)sp2.size() - 1, r2[N - D - A], A - D);
      return ret;
    };
    while (R - L > 2) {
      int Lmid = (L + L + R) / 3;
      int Rmid = (L + R + R) / 3;
      if (calc(Lmid) < calc(Rmid)) {
        L = Lmid;
      } else {
        R = Rmid;
      }
    }
    if (calc(A) >= 0 || calc(0) >= 0) {
      Ans = max(Ans, A);
    }
    for (int i = L; i <= R; ++i) {
      if (calc(i) >= 0) {
        Ans = max(Ans, A);
      }
    }
  }
  cout << Ans << '\n';
}
