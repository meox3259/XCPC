#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<string> S(3);
    for (int i = 0; i < 3; ++i) {
      cin >> S[i];
    }
    vector<vector<int>> cnt(3, vector<int> (2));
    for (int i = 0; i < 3; ++i) {
      for (char C : S[i]) {
        cnt[i][C - '0'] ++;
      }
    }
    bool ok = false;
    for (int B = 0; B < 2; ++B) {
      if (ok) {
        break;
      }
      for (int x = 0; x < 3; ++x) {
        if (ok) {
          break;
        }
        for (int y = x + 1; y < 3; ++y) {
          if (cnt[x][B] >= N && cnt[y][B] >= N) {
            vector<int> P1;
            vector<int> P2;
            for (int i = 0; i < N + N; ++i) {
              if (P1.size() == N) {
                break;
              } 
              if (S[x][i] - '0' == B) {
                P1.push_back(i);
              }
            }
            for (int i = 0; i < N + N; ++i) {
              if (P2.size() == N) {
                break;
              }
              if (S[y][i] - '0' == B) {
                P2.push_back(i);
              }
            }
            int j = 0;
            int k = 0;
            string Ans = "";
            for (int i = 0; i < N; ++i) {
              while (j < P1[i]) {
                Ans += S[x][j];
                j ++;
              }    
              j ++;
              while (k < P2[i]) {
                Ans += S[y][k];
                k ++;
              }
              k ++;
              Ans += (char)(B + '0');
            }
            while (j < N + N) {
              Ans += S[x][j];
              j ++;
            }
            while (k < N + N) {
              Ans += S[y][k];
              k ++;
            }
            cout << Ans << '\n';
            ok = true;
            break; 
          }
        }
      }
    }
  }
}
