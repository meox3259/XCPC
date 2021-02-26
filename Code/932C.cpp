#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    if (A > B) {
        swap(A, B);
    }

    int x = -1;
    int y = -1;
    for (int i = 0; A * i <= N; ++i) {
        if ((N - A * i) % B == 0) {
            x = i;
            y = (N - A * i) / B;
        }
    }

    if (x == -1 && y == -1) {
        cout << -1 << '\n';
        exit(0);
    }

    vector<int> p(N);
    int i = 0;
    for (int t = 0; t < x; ++t, i += A) {
        for (int j = i + 1; j < i + A; ++j) {
            p[j] = j - 1;
        } 
        p[i] = i + A - 1;
    }

    for (int t = 0; t < y; ++t, i += B) {
        for (int j = i + 1; j < i + B; ++j) {
            p[j] = j - 1;
        }
        p[i] = i + B - 1;
    }

    for (int i = 0; i < N; ++i) {
        cout << p[i] + 1 << " \n"[i == N - 1];
    }

    return 0;
}
