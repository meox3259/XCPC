#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    double W, H;
    cin >> W >> H;
    vector<double> X(2);
    vector<double> Y(2);
    for (int i = 0; i < 2; ++i) {
      cin >> X[i] >> Y[i];
    }
    double R = X[1] - X[0];
    double L = Y[1] - Y[0];
    double w, h;
    cin >> w >> h;
    double Ans = 1e18;
    if (h + L <= H) {
      Ans = min(Ans, max(0., h - Y[0]));  
      Ans = min(Ans, max(0., Y[1] - H + h));
    }
    if (w + R <= W) {
      Ans = min(Ans, max(0., w - X[0]));
      Ans = min(Ans, max(0., X[1] - W + w));
    }
    if (Ans > 1e17) {
      cout << -1 << '\n';
    } else {
      cout << fixed << setprecision(10);
      cout << Ans << '\n';
    }
  }
}
