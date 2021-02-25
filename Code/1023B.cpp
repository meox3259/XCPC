#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long l = max(1LL, k - n); 
    long long r = min(n, k - 1);
    long long m = (k % 2 == 0 && 1 <= k / 2 && k / 2 <= n);

    cout << max(0LL, (r - l + 1 - m) / 2) << '\n';

    return 0;
}
