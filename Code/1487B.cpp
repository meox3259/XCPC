#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long n, k;
        cin >> n >> k;

        if (n % 2 == 0) {
            cout << (k - 1) % n + 1 << '\n';
        } else {
            cout << (k - 1 + (k - 1) / (n / 2)) % n + 1 << '\n'; 
        }
    }

    return 0;
}
