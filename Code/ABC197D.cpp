#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int main() {
  int N;
  long double X0, Y0, X1, Y1;
  cin >> N >> X0 >> Y0 >> X1 >> Y1;
  long double X = 2. * pi / (long double)N; 
  long double A = (X0 + X1) / 2.;
  long double B = (Y0 + Y1) / 2.;
  long double X2 = (X0 - A) * cos(X) - (Y0 - B) * sin(X) + A;
  long double Y2 = (X0 - A) * sin(X) + (Y0 - B) * cos(X) + B;
  cout << fixed << setprecision(15);
  cout << X2 << ' ' << Y2 << '\n';
}
