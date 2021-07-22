#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> cnt(26);
    for (char C : S) {
      cnt[C - 'a'] ++;
    }
    int Min = INF;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] != 0) {
        Min = min(Min, cnt[i]);
      }
    }
    if (Min == N) {
      cout << S << '\n';
      continue;
    }
    int P = -1;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] == Min) {
        P = i;
        break;
      }
    }
    string Ans = "";
    if (Min == 1) {
      Ans += (char)(P + 'a');
      cnt[P] --;
      for (int i = 0; i < 26; ++i) {
        if (i != P) {
          for (int j = 0; j < cnt[i]; ++j) {
            Ans += (char)(i + 'a');
          }
        }
      }
      for (int i = 0; i < cnt[P]; ++i) {
        Ans += (char)(P + 'a');
      }
    } else {
      P = -1; 
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] >= 1) {
          P = i;
          break;
        }
      }
      int X = cnt[P] - 2;
      int Y = N - cnt[P];
      if (X > Y) {
        Ans += (char)(P + 'a');  
        cnt[P] --;
        int Q = -1;
        for (int i = P + 1; i < 26; ++i) {
          if (cnt[i] >= 1) {
            Q = i;
            break;
          }
        }
        int R = -1;
        for (int i = Q + 1; i < 26; ++i) {
          if (cnt[i] >= 1) {
            R = i;
            break;
          }
        }
        if (R == -1) {
          for (int i = 0; i < cnt[Q]; ++i) {
            Ans += (char)(Q + 'a');
          }
          for (int i = 0; i < cnt[P]; ++i) {
            Ans += (char)(P + 'a');
          }
        } else {
          Ans += (char)(Q + 'a');
          cnt[Q] --;
          for (int i = 0; i < cnt[P]; ++i) {
            Ans += (char)(P + 'a');
          }
          cnt[P] = 0;
          Ans += (char)(R + 'a');
          cnt[R] --;
          for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
              Ans += (char)(i + 'a');
            }
          }
        }
      } else {
        Ans += (char)(P + 'a');
        cnt[P] --;
        Ans += (char)(P + 'a');
        cnt[P] --;
        for (int i = 0; i < cnt[P]; ++i) {
          for (int j = P + 1; j < 26; ++j) {
            if (cnt[j] >= 1) {
              Ans += (char)(j + 'a');
              Ans += (char)(P + 'a');
              cnt[j] --;
              break;
            }
          }
        }
        cnt[P] = 0;
        for (int i = 0; i < 26; ++i) {
          for (int j = 0; j < cnt[i]; ++j) {
            Ans += (char)(i + 'a');
          }
        }
      }
    }
    cout << Ans << '\n';
  }
}
