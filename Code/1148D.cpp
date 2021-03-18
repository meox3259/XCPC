#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  map<pair<int, int>, int> mp;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
    A[i] --;
    B[i] --;
    mp[{A[i], B[i]}] = i;
  }
  vector<pair<int, int>> fir;
  vector<pair<int, int>> sec;
  for (int i = 0; i < N; ++i) {
    if (A[i] > B[i]) {
      fir.emplace_back(A[i], B[i]);
    } else {
      sec.emplace_back(A[i], B[i]); 
    }
  } 
  sort(fir.begin(), fir.end(), [&] (auto X, auto Y) {
    return X.second < Y.second;
  });
  vector<pair<int, int>> st;
  vector<pair<int, int>> ans;
  for (int i = 0; i < fir.size(); ++i) {
    st.push_back(fir[i]);
    if (i + 1 == fir.size() || fir[i + 1].first < fir[i].second) {
      if (st.size() > ans.size()) {
        swap(st, ans);
      }
      st.clear();
    }
  }
  st.clear();
  sort(sec.begin(), sec.end(), [&] (auto X, auto Y) {
    return X.first > Y.first;
  }); 
  for (int i = 0; i < sec.size(); ++i) {
    st.push_back(sec[i]);
    if (i + 1 == sec.size() || sec[i + 1].first > sec[i].second) {
      if (st.size() > ans.size()) {
        swap(st, ans);
      }
      st.clear();
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << mp[ans[i]] + 1 << " \n"[i + 1 == ans.size()];
  }
  return 0;
}
