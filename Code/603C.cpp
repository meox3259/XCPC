#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int g = 0;
    for (int i = 0; i < n; ++i) {
        if (k % 2 == 0) {
            if (a[i] == 0) {
                g ^= 0;
            } else if (a[i] == 1) {
                g ^= 1;
            } else if (a[i] == 2) {
                g ^= 2;
            } else {
                g ^= ((a[i] & 1) ^ 1);
            }
        } else {
            if (a[i] == 1) {
                g ^= 1;
            } else if (a[i] == 2) {
                g ^= 0;
            } else {
                if (a[i] % 2 == 1) {
                    if (a[i] == 1) {
                        g ^= 1;
                    } else if (a[i] == 3) {
                        g ^= 1;
                    } else {
                        g ^= 0;
                    }
                } else {
                    int odd = 0;
                    while (a[i] % 2 == 0) {
                        a[i] /= 2;
                        odd ^= 1;
                    }
                    if (a[i] == 1) {
                        if (odd == 1) {
                            g ^= 1;
                        } else {
                            g ^= 2;
                        }
                    } else {
                        if (a[i] == 3) {
                            if (odd == 1) {
                                g ^= 2;
                            } else {
                                g ^= 1;
                            }
                        } else {
                            if (odd == 1) {
                                g ^= 1;
                            } else {
                                g ^= 2;
                            }
                        }
                    }
                }
            }
        }
    }

    if (g) {
        cout << "Kevin" << '\n';
    } else {
        cout << "Nicky" << '\n';
    }

    return 0;
}
