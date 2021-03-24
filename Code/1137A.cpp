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
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int> (M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j]; 
    }
  }
  vector<int> S;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      S.push_back(A[i][j]);
    }
  }
  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      A[i][j] = lower_bound(S.begin(), S.end(), A[i][j]) - S.begin();
    }
  }
  int SZ = S.size();
  FenwickTree<int> fw(N * M + 1);
  vector<vector<int>> Col(N, vector<int> (M));
  vector<vector<int>> Row(N, vector<int> (M));
  vector<vector<int>> VR(N, vector<int> (M));
  vector<vector<int>> VC(N, vector<int> (M));
  for (int i = 0; i < N; ++i) {
    vector<int> vec;
    for (int j = 0; j < M; ++j) {
      vec.push_back(A[i][j]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int j : vec) {
      fw.add(j, 1);
    }
    for (int j = 0; j < M; ++j) {
      Row[i][j] = fw.query(SZ) - fw.query(A[i][j]);
      VR[i][j] = fw.query(A[i][j] - 1) + 1;
    }
    for (int j : vec) {
      fw.add(j, -1);
    }
  }
  for (int j = 0; j < M; ++j) {
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
      vec.push_back(A[i][j]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i : vec) {
      fw.add(i, 1);
    }
    for (int i = 0; i < N; ++i) {
      Col[i][j] = fw.query(SZ) - fw.query(A[i][j]);
      VC[i][j] = fw.query(A[i][j] - 1) + 1;
    }
    for (int i : vec) {
      fw.add(i, -1);
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << max(VR[i][j], VC[i][j]) + max(Col[i][j], Row[i][j]) << " \n"[j == M - 1];
    }
  }
}
