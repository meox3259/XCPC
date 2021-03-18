#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    auto query = [&] (vector<int> A, vector<int> B) -> int {
      cout << '?' << ' ' << A.size() << ' ' << B.size() << '\n'; 
      for (int i : A) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
      for (int i : B) {
        cout << i + 1 << ' ';
      }
      cout << endl;
      int ret;
      cin >> ret;
      return ret;
    };  
    auto cut = [&] (int L, int R) -> vector<int> {
      vector<int> A;
      for (int i = L; i <= R; ++i) {
        A.push_back(i);
      }
      return A;
    };
    int P = -1;
    for (int i = 0; i < N - 1; ++i) {
      if (query(cut(0, i), cut(i + 1, i + 1)) != 0) {
        P = i + 1;
        break;
      }
    }
    int L = -1;
    int R = P;
    while (R - L > 1) {
      int mid = L + R >> 1;
      if (query(cut(mid, P - 1), cut(P, P)) != 0) {
        L = mid;
      } else {
        R = mid;
      }
    }
    vector<int> Ans;
    for (int i = 0; i < P; ++i) {
      if (i != L) {
        Ans.push_back(i);
      }
    }
    for (int i = P + 1; i < N; ++i) {
      if (query({P}, {i}) == 0) {
        Ans.push_back(i);
      }
    }
    cout << '!' << ' ' << Ans.size();
    for (int i : Ans) {
      cout << ' ' << i + 1;
    }
    cout << endl;
  }
  return 0;
}
