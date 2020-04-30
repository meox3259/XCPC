template <class T> 
class FenwickTree {
	int N;
	vector<T> v;

	public:
	FenwickTree(int N) : N(N), v(N) {}

	void add(int p, T val) {
		for(int i = p; i < N; i += (i & -i)) {
			v[i] += val;
		}
	}

	T query(int p) {
		T sum = 0;
		for(int i = p; i >= 1; i -= (i & -i)) {
			sum += v[i];
		}
		return sum;
	}
};
