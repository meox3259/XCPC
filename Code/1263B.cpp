#include <bits/stdc++.h>
using namespace std;
string p[20];
int vis[20];
int main() {
	int T; cin >> T;
	while(T--) {
		memset(vis, 0, sizeof(vis));
		int n, ans = 0; cin >> n;
		for(int i = 0; i < n; ++i) cin >> p[i];
		for(int i = 0; i < n; ++i) vis[p[i][0] - '0'] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(p[i] == p[j]) {
					for(int k = 0; k < 10; ++k) {
						if(!vis[k]) {
							vis[k] = 1;
							p[i][0] = (char)(k + '0');
							break;
						}
					}
					++ans;
					break;
				}
			}	
		}
		printf("%d\n", ans);
		for(int i = 0; i < n; ++i) cout << p[i] << endl;
	}
	return 0;
}
