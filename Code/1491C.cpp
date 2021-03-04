#include <bits/stdc++.h>

using namespace std;

class dsu {
  private:
    vector<int> dat;
    int components_;
  public:
    dsu() {}
    explicit dsu(int n) : dat(n, -1), components_(n) {}
    
    int size() {
        return dat.size();
    }
    int root(int x) {
        assert(0 <= x), assert(x < size());
        return dat[x] < 0 ? x : dat[x] = root(dat[x]);
    }
    pair<int, int> unite(int x, int y) {
        assert(0 <= x), assert(x < size());
        assert(0 <= y), assert(y < size());
        x = root(x), y = root(y);
        if (x == y) {
            return { x, -1 };
        }
        components_ --;
        if (-dat[x] < -dat[y]) {
            swap(x, y);
        }
        dat[x] += dat[y];
        dat[y] = x;
        return { x, y };
    }
    bool same(int x, int y) {
        assert(0 <= x), assert(x < size());
        assert(0 <= y), assert(y < size());
        return root(x) == root(y);
    }
    int size(int x) {
        assert(0 <= x), assert(x < size());
        return -dat[root(x)];
    }
    int components() {
        return components_;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<int> S(n);
        for (int i = 0; i < n; ++i) {
            cin >> S[i];
        }

        long long ans = 0;

        dsu dsu(n + 1);
        vector<int> r(n + 1);
        for (int i = 0; i < n; ++i) {
            if (S[i] == 1) {
                r[i] = i + 1;
            } else {
                r[i] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            ans += S[i] - 1;
            S[i] = min(S[i], n);
            int TT = S[i];
            for (int j = 0; j < TT - 1; ++j) {
                int k = i; 
                while (k < n) {
                    if (S[k] == 1) {
                        r[k] = max(k + 1, r[r[k]]);
                        k = r[k];
                    } else {
                        S[k] --;
                        k += S[k] + 1;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
