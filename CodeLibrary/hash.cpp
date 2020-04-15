class Hash {
public:
	vector<long long> hash1;
	vector<long long> hash2;
	vector<vector<long long> > power;
	vector<long long> V;
	void init(string s, long long P1, long long P2) {
		V.resize(2);
		V[0] = P1;
		V[1] = P2;
		hash1.resize(s.size() + 1, 0);
		hash2.resize(s.size() + 1, 0);
		power.resize(2);
		for(int i = 0; i < 2; ++i) {
			power[i].resize(s.size() + 1, 0);
		}
		power[0][0] = 1;
		power[1][0] = 1;
		for(int i = 1; i <= s.size(); ++i) {
			hash1[i] = (152LL * hash1[i - 1] + 1LL * (s[i - 1] - '0')) % V[0];
			hash2[i] = (152LL * hash2[i - 1] + 1LL * (s[i - 1] - '0')) % V[1];
			power[0][i] = power[0][i - 1] * 152 % V[0];
			power[1][i] = power[1][i - 1] * 152 % V[1];
		}
	}
	pair<long long, long long> get_hash(int l, int r) {
		long long X1 = (hash1[r + 1] - hash1[l] * power[0][r - l + 1] + V[0] * V[0]) % V[0];
		long long X2 = (hash2[r + 1] - hash2[l] * power[1][r - l + 1] + V[1] * V[1]) % V[1];
		return {X1, X2};
	}
};
