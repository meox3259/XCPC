#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<long long> sum(k + 1);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j * i <= k; ++j) {
            sum[i * j] ++;
        } 
    }

    for (int i = 1; i <= k; ++i) {
        sum[i] += sum[i - 1];
    }

    long long ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += sum[k / i]; 
    }

    cout << ans << '\n';

    return 0;
}
