#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto query = [&] (int l, int r) -> int {
        cout << '?' << ' ' << l << ' ' << r << endl;
        int ret;
        cin >> ret;
        return ret;
    };

    int p = query(1, n);

    if (p > 1 && query(1, p) == p) {
        int l = 0;
        int r = p;
        while (r - l > 1) {
            int mid = l + r >> 1;
            int cur = query(mid, p);
            if (cur == p) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << '!' << ' ' << l << endl;
    } else {
        int l = p;
        int r = n + 1;
        while (r - l > 1){
            int mid = l + r >> 1;
            int cur = query(p, mid);
            if (cur == p) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << '!' << ' ' << r << endl;
    }

    return 0;
}
