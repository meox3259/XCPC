#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int m = 1 << n;
	vector<int> s(m);
	for (int i = 0; i < m; ++i) {
		cin >> s[i];
	}

    sort(s.begin(), s.end());
    for (int i = 0; i < m; ++i) {
        cerr << s[i] << " \n"[i == m - 1];
    }

    multiset<int> st;
    multiset<int> rem;
    for (int i : s) {
        rem.emplace(i);
    }
    st.emplace(*rem.rbegin());
    rem.erase(rem.find(*rem.rbegin()));
    for (int i = 0; i < n; ++i) {
        auto tmp = st;
        vector<int> ban;
        auto it = -- rem.end(); 
        while (ban.size() < (1 << i)) {
            auto itp = tmp.upper_bound(*it);
            if (itp != tmp.end()) {
                ban.emplace_back(*it);
                tmp.erase(itp);
            }
            if (it == rem.begin()) {
                break;
            }
            it = prev(it);
        }
        if (ban.size() < (1 << i)) {
            cout << "No" << '\n';
            exit(0);
        }
        for (int j : ban) {
            rem.erase(rem.find(j));
            st.emplace(j);
        }
    }

    cout << "Yes" << '\n';

	return 0;
}
