#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int sum = 0;
        for (int i : a) {
            sum += i;
        }

        if (sum == 0) {
            cout << "NO" << '\n';
        } else {
            if (sum < 0) {
                sort(a.begin(), a.end());
            } else {
                sort(a.begin(), a.end(), greater<int> ());
            }
            cout << "YES" << '\n';
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " \n"[i == n - 1];
            }
        }
    }

    return 0;
}
