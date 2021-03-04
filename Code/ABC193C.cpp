#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long ans = N;

    unordered_map<long long, int> mp;

    for (long long i = 2; i * i <= N; ++i) {
        long long j = i * i;
        while (j <= N) {
            if (mp.find(j) == mp.end()) {
                mp[j] = 1;
                ans --;
            }
            j = j * i;
        }
    }

    cout << ans << '\n';

    return 0;
}
