#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string l, r;
  cin >> n >> l >> r; 
  auto add = [&] (string v) -> string {
    int i = (int)v.size() - 1; 
    while (v[i] == '1') {
      v[i] = '0';
      i--;
    }
    v[i] = '1';
    return v;
  };
  if (l == r) {
    cout << r << '\n';
  } else if (l[0] != r[0]){
    cout << string(n, '1') << '\n'; 
  } else if (add(l) == r || r.back() == '1') {
    cout << r << '\n';
  } else {
    cout << add(r) << '\n';
  }
}
