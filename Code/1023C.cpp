#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans = "";

    int both = 0;
    int half = 0;
    for (char c : s) {
        if (ans.size() == k) {
            break;
        }
        if (c == '(') {
            half ++;
            ans += '(';
            if (both + half * 2 == k) {
                for (int i = 0; i < half; ++i) {
                    ans += ')';
                }
                break;
            }
        } else {
            half --;
            both += 2;
            ans += ')';
        }
    }

    cout << ans << '\n';

    return 0;
}
