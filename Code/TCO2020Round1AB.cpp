#include <bits/stdc++.h>

using namespace std;

class ThreeNeighbors {
	public:
	vector<string> construct(int n) {
		vector<string> s;
		s.resize(49);

		for(int i = 0; i < 49; ++i) {
			for(int j = 0; j < 49; ++j) {
				if((i + j) & 1) {
					s[i] += '.';
				} else {
					s[i] += 'X';
				}
			}
		}

		int sum = 0;

		for(int i = 0; i < 49; ++i) {
			s[0][i] = 'X';
		}

		for(int i = 0; i < 49; ++i) {
			s[i][0] = 'X';
		}

		for(int i = 0; i < 49; ++i) {
			s[48][i] = 'X';
		}

		for(int i = 0; i < 49; ++i) {
			s[i][48] = 'X';
		}

		for(int i = 2; i < 49 / 2; ++i) {
			for(int j = 2; j < 49 / 2; ++j) {
				if(((i + j) & 1) && sum + 4 <= n) {
					sum += 4;
					s[i * 2 - 1][j * 2 - 1] = '.';
				}
			}
		}

		int d = n - sum;

		if(d == 1) {
			s[0][0] = '.';
		}

		if(d == 2) {
			s[0][0] = '.';
			s[48][0] = '.';
		}

		if(d == 3) {
			s[0][0] = '.';
			s[48][0] = '.';
			s[0][48] = '.';
		}

		return s;
	}
};
