#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5, m = 2e5 + 5;
int n;
int a[maxn];
vector<pair<int, int> > v[m];
int main() {
	scanf("%d", &n);
	for(int i = 1; i * 2 + 1 < m; ++i) 
		for(int j = i + 1; 1LL * j * j - 1LL * i * i < m; ++j)
			v[j * j - i * i].push_back(make_pair(i, j));
	for(int i = 2; i <= n; i += 2) {
		int x; scanf("%d", &x);
		for(auto t : v[x]) 
			if(t.first > a[i - 2]) {
				a[i - 1] = t.first;
				a[i] = t.second;
				break;
			}
		if(!a[i]) return puts("No");
	}	
	puts("Yes");
	for(int i = 1; i <= n; ++i) printf("%lld ", 1LL * a[i] * a[i] - 1LL * a[i - 1] * a[i - 1]);
	return 0;
}
