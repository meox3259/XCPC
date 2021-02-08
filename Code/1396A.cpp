#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << -a[0] << '\n';
        exit(0);
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[1LL * (n - 1) * i % n] = i; 
    }

    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 0; i < n - 1; ++i) {
        long long d = a[i] % n;
        if (a[i] < 0) {
            d = (a[i] % n + n) % n;
        } 
        cout << 1LL * mp[(n - d) % n] * (n - 1) << " \n"[i == n - 2];
        a[i] += 1LL * mp[(n - d) % n] * (n - 1);
    }

    cout << 2 << ' ' << n << '\n';
    for (int i = 1; i < n; ++i) {
        long long d = a[i] % n;
        if (a[i] < 0) {
            d = (a[i] % n + n) % n;
        } 
        cout << 1LL * mp[(n - d) % n] * (n - 1) << " \n"[i == n - 1];
        a[i] += 1LL * mp[(n - d) % n] * (n - 1);
    }

    cout << 1 << ' ' << n << '\n'; 
    for (int i = 0; i < n; ++i) {
        cout << -a[i] << " \n"[i == n - 1];
    }

    return 0;
}
