#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    vector<char> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> d[i];
    }

    long double l = 0;
    long double r = 1e9;
    
    auto calc = [&] (long double t) -> long double {
        long double xmin = 1e9;
        long double xmax = -1e9;
        long double ymin = 1e9;
        long double ymax = -1e9;
        for (int i = 0; i < n; ++i) {
            long double X = x[i];
            long double Y = y[i];
            if (d[i] == 'R') {
                X += t;
            }
            if (d[i] == 'L') {
                X -= t;
            }
            if (d[i] == 'U') {
                Y += t;
            }
            if (d[i] == 'D') {
                Y -= t;
            }
            xmin = min(xmin, X);
            xmax = max(xmax, X);
            ymin = min(ymin, Y);
            ymax = max(ymax, Y);
        }
        return (xmax - xmin) * (ymax - ymin);
    };

    for (int i = 0; i < 300; ++i) {
        long double lmid = (l + l + r) / 3.;
        long double rmid = (l + r + r) / 3.;

        if (calc(lmid) < calc(rmid)) {
            r = rmid;
        } else {
            l = lmid;
        }
    }

    cout << fixed << setprecision(15);
    cout << calc(l) << '\n';

    return 0;
}
