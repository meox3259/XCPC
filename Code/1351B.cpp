#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b) {
            swap(a, b);
        }
        if(c > d) {
            swap(c, d);
        }
        if(b == d && a + c == b) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}