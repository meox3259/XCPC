#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
class ParenthesesDiv1Easy {
	public:
		int st[maxn];
		vector<int> correct(string s) {
			memset(st, 0, sizeof(st));
			int n = s.size(), top = 0;
			for(int i = 0; i < n; ++i) {
				if(s[i] == '(') st[++top] = i;
				else {
					if(top && s[st[top]] == '(') --top;
					else st[++top] = i;
				}
			}
			int cnt1 = 0, cnt2 = 0;
			for(int i = 1; i <= top; ++i) if(s[st[i]] == '(') ++cnt1; else ++cnt2;
			vector<int> ans;
			if(!top) return ans;
			if(top & 1) return {-1};
			if(!cnt1) {
				ans.push_back(st[1]);
				ans.push_back(st[top / 2]);
			} else if(!cnt2) {
				ans.push_back(st[top / 2 + 1]);
				ans.push_back(st[top]);
			} else if(cnt1 == cnt2) {
				ans.push_back(st[1]);
				ans.push_back(st[top / 2]);
				ans.push_back(st[top / 2] + 1);
				ans.push_back(st[top]);
			} else if(cnt1 > cnt2) {
				ans.push_back(st[1]);
				ans.push_back(st[cnt2]);
				ans.push_back(st[top / 2 + 1]);
				ans.push_back(st[top]);
			} else if(cnt1 < cnt2) {
				ans.push_back(st[top / 2 + 1 + (cnt2 - cnt1 + 1) / 2]);
				ans.push_back(st[top]);
				ans.push_back(st[1]);
				ans.push_back(st[top / 2]);
			}
			return ans;
		}
};   


