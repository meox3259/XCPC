#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	int n;
	cin >> n;

	int sr, sc;
	cin >> sr >> sc;

	string s;
	cin >> s;

	string t;
	cin >> t;

	map<char, int> id;
	id['L'] = 0;
	id['R'] = 1;
	id['U'] = 2;
	id['D'] = 3;

	vector<int> cnts(4);
	vector<int> cntt(4);
	for(int i = 0; i < n; ++i) {
		cnts[id[s[i]]] += 1;
		if(sr - cnts[2] + cntt[3] <= 0 || sr + cnts[3] - cntt[2] > h || sc - cnts[0] + cntt[1] <= 0 || sc + cnts[1] - cntt[0] > w) {
			cout << "NO" << '\n';
			exit(0);
		}
		if(cnts[id[t[i]] ^ 1] > 0) {
			cnts[id[t[i]] ^ 1] -= 1;
		} else {
			cntt[id[t[i]]] += 1;
		}
	}

	bool okw = false;
	for(int i = -cntt[0]; i <= cntt[1]; ++i) {
		int cur = sc + i;
		if(1 <= cur - cnts[0] && cur + cnts[1] <= w) {
			okw = true;
		}
	}

	bool okh = false;
	for(int i = -cntt[2]; i <= cntt[3]; ++i) {
		int cur = sr + i;
		if(1 <= cur - cnts[2] && cur + cnts[3] <= h) {
			okh = true;
		}
	}

	if(okw && okh) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}

	return 0;
}
