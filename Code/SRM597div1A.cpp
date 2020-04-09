#include <bits/stdc++.h>

using namespace std;

class LittleElephantAndString {
	public:
	int getNumber(string A, string B) {
		int n = A.size();

		int ans = n;

		vector<int> cnt;
		cnt.resize(26);

		for(char c : A) {
			++cnt[c - 'A'];
		}

		for(char c : B) {
			--cnt[c - 'A'];
		}

		for(int i : cnt) {
			if(i != 0) {
				return -1;
			}
		}

		for(int i = n - 1, j = n - 1; i >= 0; --i) {
			while(j >= 0 && A[j] != B[i]) {
				--j;
			}

			if(j < 0) {
				break;
			}

			--j;
			--ans;
		}

		return ans;
	}
};
