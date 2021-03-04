#include <bits/stdc++.h>
using namespace std;
class sgt {
  public:
  vector<int> sum;
  vector<int> lc;
  vector<int> rc;
  int Pool = 0;
  sgt() {}
  sgt(int N) : sum(N * 50), lc(N * 50), rc(N * 50) {}
  void update(int l, int r, int &x, int p, int v) {
    if (x == 0) {
      x = ++Pool; 
    }
    sum[x] += v;
    if (l == r) {
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      update(l, mid, lc[x], p, v);
    } else {
      update(mid + 1, r, rc[x], p, v);
    }
  }
  int query(int l, int r, int x, int a, int b) {
    if (l > b || r < a || x == 0) {
      return 0;
    }
    if (l >= a && r <= b) {
      return sum[x];
    }
    int mid = l + r >> 1;
    return query(l, mid, lc[x], a, b) + query(mid + 1, r, rc[x], a, b);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int> pa;
  vector<int> pb;
  vector<int> na;
  vector<int> nb;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      pa.push_back(a[i]);
    } else {
      na.push_back(-a[i]);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (b[i] > 0) {
      pb.push_back(b[i]);
    } else {
      nb.push_back(-b[i]);
    }
  }
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());
  sort(na.begin(), na.end());
  sort(nb.begin(), nb.end());
  int M = 1000000005;
  int L = 0;
  set<int> S;
  for (int i : pa) {
    S.insert(i);
  }
  int LT = 0;
  for (int i : pb) {
    if (S.find(i) != S.end()) {
      LT ++;
    }
  }
  sgt SL(m);
  int root = 0;
  for (int i : pb) {
    SL.update(0, M, root, i, 1);
  }
  for (int i = 0; i < pb.size(); ++i) {
    if (S.find(pb[i]) != S.end()) {
      LT --;
    }
    int cnt = upper_bound(pa.begin(), pa.end(), pb[i]) - pa.begin();
    int sum = SL.query(0, M, root, pb[i] - cnt + 1, pb[i]);
    L = max(L, sum + LT);
  }
  int R = 0;
  S.clear();
  for (int i : na) {
    S.insert(i);
  }
  int RT = 0;
  for (int i : nb) {
    if (S.find(i) != S.end()) {
      RT ++;
    }
  }
  sgt SR(m);
  root = 0;
  for (int i : nb) {
    SR.update(0, M, root, i, 1);
  }
  for (int i = 0; i < nb.size(); ++i) {
    if (S.find(nb[i]) != S.end()) {
      RT --;
    }
    int cnt = upper_bound(na.begin(), na.end(), nb[i]) - na.begin();
    int sum = SR.query(0, M, root, nb[i] - cnt + 1, nb[i]);
    R = max(R, sum + RT);
  }
  cout << L + R << '\n';
  }
  return 0;
}
