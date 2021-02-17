#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<long long> p;
    for (long long a = 1; a * a <= 2000000000; ++a) {
        long long s = a * a;
        if ((s - 1) % 2 == 0 && (s - 1) / 2 >= a) {
            p.emplace_back((s - 1) / 2 + 1); 
        } 
    }
    
    sort(p.begin(), p.end());

    while (T --) {
        long long n;
        cin >> n;

        cout << upper_bound(p.begin(), p.end(), n) - p.begin() << '\n';
    }

    return 0;
}
