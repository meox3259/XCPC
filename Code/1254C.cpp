#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ask(int t, int i, int j, int k) {
	cout << t << " " << i << " " << j << " " << k << endl;
	ll ret;
	cin >> ret;
	return ret;
}
int main() {
	cin >> n;
	int piv = 2;
	for(int i = 3; i <= n; ++i) {
		if(ask(2, 1, piv, i) == -1) {
			piv = i;
		}
	}
	vector<pair<ll, int> > vec;
	for(int i = 2; i <= n; ++i) {
		if(i != piv) {
			vec.emplace_back(ask(1, 1, piv, i), i);
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int far = vec[0].second;
	deque<int> q;
	q.push_back(far);
	for(int i = 1; i < vec.size(); ++i) {
		if(ask(2, 1, far, vec[i].second) == -1) {
			q.push_front(vec[i].second);
		} else {
			q.push_back(vec[i].second);
		}
	} 
	q.push_front(piv);
	q.push_front(1);
	cout << "0";
	for(auto x : q) {
		cout << " " << x;
	}
	return 0;
}
