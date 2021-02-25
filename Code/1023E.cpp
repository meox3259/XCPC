#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto query = [&] (int r1, int c1, int r2, int c2) -> bool {
        cout << '?' << ' ' << r1 + 1 << ' ' << c1 + 1 << ' ' << r2 + 1 << ' ' << c2 + 1 << endl;
        string ret;
        cin >> ret;
        if (ret == "YES") {
            return true;
        } else {
            return false;
        }
    };

    auto dis = [&] (int r1, int c1, int r2, int c2) -> int {
        return abs(r1 - r2) + abs(c1 - c2);
    };

    int x = 0;
    int y = 0;
    vector<pair<int, int> > path;
    path.emplace_back(0, 0);
    while (dis(0, 0, x, y) < n - 1) {
        if (query(x + 1, y, n - 1, n - 1)) {
            x ++;
        } else {
            y ++;
        }
        path.emplace_back(x, y);
    }

    int m = path.size(); 
    x = n - 1;
    y = n - 1;
    vector<pair<int, int> > b;
    b.emplace_back(n - 1, n - 1);
    for (int i = m - 2; i >= 0; --i) {
        if (query(0, 0, x, y - 1)) {
            y --;
        } else {
            x --;
        }
        b.emplace_back(x, y);
    }

    b.pop_back();
    while (!b.empty()) {
        path.push_back(b.back());
        b.pop_back();
    }

    cout << '!' << ' ';
    for (int i = 0; i + 1 < path.size(); ++i) {
        if (path[i].first != path[i + 1].first) {
            cout << 'D';
        } else {
            cout << 'R';
        }
    }

    cout << endl;

    return 0;
}
