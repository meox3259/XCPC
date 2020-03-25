#include <bits/stdc++.h>

using namespace std;

class Dating {
	bool check(string s) {
		bool l = false;
		bool r = false;

		for(auto c : s) {
			if(isupper(c)) {
				l = true;
			}

			if(islower(c)) {
				r = true;
			}
		}

		return l && r;
	}

	public:
		string dates(string s, int k) {
			string ans = "";

			while(check(s)) {
				for(int i = 0; i < k - 1; ++i) {
					char c = s[0];
					
					s.erase(s.begin());
					s += c;
				}

				char cho = *s.begin();

				ans += cho;

				s.erase(s.begin());

				char hot = 127;

				for(auto c : s) {
					if(islower(cho) != islower(c)) {
						hot = min(hot, c);
					}
				}

				for(int i = 0; i < s.size(); ++i) {
					if(s[i] == hot) {
						s.erase(i, 1);
						break;
					}
				}

				ans += hot;
				ans += ' ';
			}	

			if(!ans.empty()) {
				ans.pop_back();
			}

			return ans;
		}
};

/*
int main() {
	Dating Test;

	string s;
	int k;

	cin >> s;
	cin >> k;

	cout << Test.dates(s, k) << '\n';

	return 0;
} */
