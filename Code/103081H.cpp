#include <bits/stdc++.h>
using namespace std;
struct node {
  node *lc;
  node *rc;
  int sum;
  node() : lc(nullptr), rc(nullptr), sum(0) {}
};
struct tree {
  node *update(int l, int r, node *&x, int p, int v) {
    node *y = new node;
    if (x != nullptr) {
      *y = *x;
    }
    y->sum += v;
    if (l == r) {
      return y;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      y->lc = update(l, mid, y->lc, p, v);
    } else {
      y->rc = update(mid + 1, r, y->rc, p, v);
    }
    return y;
  }
  int query(int l, int r, node *x, int a, int b) {
    if (x == nullptr || l > b || r < a) {
      return 0;
    }
    if (l >= a && r <= b) {
      return x->sum;
    }
    int mid = l + r >> 1;
    return query(l, mid, x->lc, a, b) + query(mid + 1, r, x->rc, a, b);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<node *> root(n + 1);
  tree tree;
  for (int i = 0; i < n; ++i) {
    root[i + 1] = root[i];
    string s;
    if (i == 0) {
      getline(cin, s);
    }
    getline(cin, s);
    stringstream str(s);
    char op;
    while (str >> op) {
      int x;
      str >> x;
      if (op == '+') {
        root[i + 1] = tree.update(0, n, root[i + 1], x, 1); 
      } else {
        root[i + 1] = tree.update(0, n, root[i + 1], x, -1);
      }
    }
  }
  int x = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    x = (x + tree.query(0, n, root[d], x, n)) % n;
  }
  cout << x << '\n';
}
