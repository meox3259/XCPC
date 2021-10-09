#include <bits/stdc++.h>
using namespace std;
struct node {
  int sum, mxp, mxs, mnp, mns;
  node() {}
  node(int v) : sum(v), mxp(max(0, v)), mnp(min(0, v)), mxs(max(0, v)), mns(min(0, v)) {}
};
node merge (node lhs, node rhs) {
  node ret;
  ret.sum = lhs.sum + rhs.sum;
  ret.mxp = max(lhs.mxp, lhs.sum + rhs.mxp);
  ret.mnp = min(lhs.mnp, lhs.sum + rhs.mnp);
  ret.mxs = max(rhs.mxs, rhs.sum + lhs.mxs);
  ret.mns = min(rhs.mns, rhs.sum + lhs.mns);
  return ret;
}

struct sgt {
  vector<node> t;
  sgt() {}
  sgt(int n) : t(n * 4) {}
  void update(int l, int r, int x, int p, int v) {
    if (l == r) {
      t[x] = node(v); 
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      update(l, mid, x << 1, p, v);
    } else {
      update(mid + 1, r, x << 1 | 1, p, v);
    }
    t[x] = merge(t[x << 1], t[x << 1 | 1]);
  }
  node query(int l, int r, int x, int a, int b) {
    if (l > b || r < a) {
      return node(0);
    }
    if (l >= a && r <= b) {
      return t[x];
    }
    int mid = l + r >> 1;
    return merge(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n); 
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int i, int j) {
    return a[i] < a[j];
  });
  sgt sgt(n);
  for (int i = 0; i < n; ++i) {
    sgt.update(0, n - 1, 1, i, 1);
  }
  vector<int> ans(n);
  for (int i = 0, j = 0; i < n; i = j + 1) {
    while (j < n - 1 && a[p[j + 1]] == a[p[i]]) {
      j++;
    }
    for (int k = i; k <= j; ++k) {
      ans[p[k]] = max(ans[p[k]], (sgt.query(0, n - 1, 1, 0, p[k]).mxs + 
                                    sgt.query(0, n - 1, 1, p[k] + 1, n - 1).mxp) / 2); 
    }
    for (int k = i; k <= j; ++k) {
      sgt.update(0, n - 1, 1, p[k], -1);
    }
    for (int k = i; k <= j; ++k) {
      ans[p[k]] = max(ans[p[k]], (-sgt.query(0, n - 1, 1, 0, p[k]).mns - 
                                    sgt.query(0, n - 1, 1, p[k] + 1, n - 1).mnp - 1) / 2);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
