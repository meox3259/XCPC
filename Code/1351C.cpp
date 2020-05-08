#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        string s;
        cin >> s;
        int n = s.size();
        map<tuple<int, int, int, int>, bool> vis;
        int x = 0;
        int y = 0;
        int ans = 0;
        for(char c : s) {
            int dx = 0;
            int dy = 0;
            if(c == 'N') {
                dx = -1;
            }
            if(c == 'S') {
                dx = 1;
            }
            if(c == 'E') {
                dy = 1;
            }
            if(c == 'W') {
                dy = -1;
            }
            if(!vis[{x, y, x + dx, y + dy}]) {
                ans += 5;
            } else {
                ans += 1;
            }
            vis[{x, y, x + dx, y + dy}] = true;
            vis[{x + dx, y + dy, x, y}] = true;
            x = x + dx;
            y = y + dy;
        }
        cout << ans << '\n';
    }

    return 0;
}