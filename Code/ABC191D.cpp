#include <bits/stdc++.h>

using namespace std;

#define double long double

const double eps = 1e-9;

int main() {
    double x, y, R;
    cin >> x >> y >> R;

    long long ans = 0;
    for (long long i = floor(x + 0.5); fabs((double)x - i) <= R; ++i) {
        long long l = floor(y + 0.5) - 1;
        long long r = 200001;
        long long low = floor(y + 0.5);
        while (r - l > 1) {
            long long mid = l + r >> 1;
            if ((double)(i - x) * (i - x) + (mid - y) * (mid - y) <= R * R + eps) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += l - low + 1;
        low = floor(y - 0.5);
        r = low + 1;
        l = -200001;
        while (r - l > 1) {
            long long mid = l + r >> 1;
            if ((double)(i - x) * (i - x) + (mid - y) * (mid - y) <= R * R + eps) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans += low - r + 1;
    }

    for (long long i = floor(x - 0.5); fabs((double)x - i) <= R; --i) {
        long long l = floor(y + 0.5) - 1;
        long long r = 200001;
        long long low = floor(y + 0.5);
        while (r - l > 1) {
            long long mid = l + r >> 1;
            if ((double)(i - x) * (i - x) + (mid - y) * (mid - y) <= R * R + eps) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += l - low + 1;
        low = floor(y - 0.5);
        r = low + 1;
        l = -200001;
        while (r - l > 1) {
            long long mid = l + r >> 1;
            if ((double)(i - x) * (i - x) + (mid - y) * (mid - y) <= R * R + eps) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans += low - r + 1;
    }

    cout << ans << '\n';

    return 0;
}
