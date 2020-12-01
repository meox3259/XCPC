#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	auto query = [&] (int i, int j, int k) {
		if(k == 0) {
			cout << "AND ";
		} else if(k == 1) {
			cout << "OR ";
		} else if(k == 2) {
			cout << "XOR "; 
		}
		cout << i + 1 << ' ' << j + 1 << endl;
		int ret;
		cin >> ret;
		return ret;
	};

	int S = 0;
	for(int i = 0; i < n; ++i) {
		S ^= i;
	}

	vector<int> ans(n);
	vector<int> Xor(n);

	for(int i = 1; i < n; ++i) {
		Xor[i] = query(0, i, 2);
	}

	vector<vector<int> > v(n);
	for(int i = 0; i < n; ++i) {
		v[Xor[i]].emplace_back(i);
	}

	int p1 = -1;
	int p2 = -1;
	for(int i = 0; i < n; ++i) {
		if(v[i].size() >= 2) {
			p1 = v[i][0];
			p2 = v[i][1];
			break;
		}
	}

	if(p1 != -1 && p2 != -1) {
		int v = query(p1, p2, 0); 	
		Xor[0] = Xor[p1] ^ v;
		for(int i = 1; i < n; ++i) {
			Xor[i] ^= Xor[0];
		}
		cout << "!";
		for(int i = 0; i < n; ++i) {
			cout << " " << Xor[i];
		}
		cout << endl;
	} else {
		int a = 0;
		int b = -1;
		int c = -1;
		for(int i = 1; i < n; ++i) {
			if(Xor[i] == n - 1) {
				b = i;
			}
		}		
		for(int i = 1; i < n; ++i) {
			if(i != b) {
				c = i;
			}
		}
		int axb = Xor[b];
		int bxc = Xor[b] ^ Xor[c];
		int cxa = Xor[c];
		int aob = 0;
		int boc = query(b, c, 0);
		int coa = query(c, a, 0);
		int ab = axb + aob * 2;
		int bc = bxc + boc * 2;
		int ca = cxa + coa * 2;
		int sum = (ab + bc + ca) / 2;
		Xor[0] = sum - bc;
		for(int i = 1; i < n; ++i) {
			Xor[i] ^= Xor[0];
		}
		cout << "!";
		for(int i = 0; i < n; ++i) {
			cout << ' ' << Xor[i];
		}
		cout << endl;
	}

	return 0;
}
