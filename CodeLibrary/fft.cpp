namespace poly { //method : use c = multiply(a, b)
	const double pi = acos(-1);

	class comp {
		public:
		double x, y;

		comp(double _x = 0, double _y = 0) : x(_x), y(_y) {}
		inline comp friend operator + (const comp &a, const comp &b) {
			return { a.x + b.x, a.y + b.y };
		}
		inline comp friend operator - (const comp &a, const comp &b) {
			return { a.x - b.x, a.y - b.y };
		}
		inline comp friend operator * (const comp &a, const comp &b) {
			return { a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
		}
	};
	inline comp conj(const comp &a) {
		return comp(a.x, -a.y);
	}
	inline comp inv(const comp &a) {
		double n = a.x * a.x + a.y * a.y;
		return { a.x / n, -a.y / n };
	}

	vector<int> rev = {0, 1};
	vector<comp> Root = {2, comp(1)};

	void init(int n) {
		if(n <= Root.size()) {
			return;
		}
		rev.resize(n);
		for(int i = 0; i < n; ++i) {
			rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
		}
		Root.reserve(n);
		for(int k = Root.size(); k < n; k = k * 2) {
			Root.resize(2 * k);
			double a = pi / k;
			comp z = { cos(a), sin(a) };
			for(int i = k / 2; i < k; ++i) {
				Root[i * 2] = Root[i];
				Root[i * 2 + 1] = Root[i] * z;
			}
		}
	}

	void dft(vector<comp> &a, int n) {
		init(n);
		int s = __builtin_ctz(rev.size() / n);
		for(int i = 0; i < n; ++i) {
			if(i < rev[i] >> s) {
				swap(a[i], a[rev[i] >> s]);
			}
		}
		for(int k = 1; k < n; k = k * 2) {
			for(int i = 0; i < n; i = i + k * 2) {
				for(int j = 0; j < k; ++j) {
					comp t = Root[j + k] * a[i + j + k];
					a[i + j + k] = a[i + j] - t;
					a[i + j] = a[i + j] + t; 
				}
			}
		}
	}

	vector<comp> multiply(vector<comp> a, vector<comp> b) { // return a * b size = sz(a) + sz(b)
		int s = a.size() + b.size() - 1;
		if(s <= 0) {
			return {};
		}
		int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0;
		int n = 1 << L;
		a.resize(n);
		dft(a, n);
		b.resize(n);
		dft(b, n);
		comp d = inv({ n, 0 });
		for(int i = 0; i < n; ++i) {
			a[i] = a[i] * b[i] * d;
		}
		reverse(a.begin() + 1, a.end());
		dft(a, n);
		a.resize(s);
		return a;
	}
}


