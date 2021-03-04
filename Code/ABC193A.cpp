#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b;
    cin >> a >> b;

    cout << fixed << setprecision(10);
    cout << (a - b) / a * 100. << '\n';

    return 0;
}
