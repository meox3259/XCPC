#include <bits/stdc++.h>

using namespace std;

template <class T>
class Vec {
	T x;
	T y;

	public:
	Vec(T _x, T _y) : x(_x), y(_y) {}

	friend Vec operator - (const Vec &a, const Vec &b) {
		return Vec(a.x - b.x, a.y - b.y);
	}
	friend Vec operator + (const Vec &a, const Vec &b) {
		return Vec(a.x + b.x, a.y + b.y);
	}
	friend T operator * (const Vec &a, const Vec &b) {
		return a.x * b.x + a.y * b.y;
	}
	friend T operator ^ (const Vec &a, const Vec &b) {
		return a.x * b.y - a.y * b.x;
	}
};

class Constellation {
	public:
	double expectation(vector <int> x, vector <int> y, vector <int> prob) {
		int n = x.size();
		double ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				Vec<int> a = { x[i], y[i] };
				Vec<int> b = { x[j], y[j] };
				double p = prob[i] / 1000. * prob[j] / 1000.;
				for(int k = 0; k < n; ++k) {
					if(k != i && k != j) {
						Vec<int> c = { x[k], y[k] };
						if(((a - c) ^ (b - c)) < 0) {
							p = p * (1. - prob[k] / 1000.);	
						} else if(((a - c) ^ (b - c)) == 0 && ((c ^ a) > 0) == ((b ^ c) > 0)) {
							p = p * (1. - prob[k] / 1000.);
						}
					}
				}		
				ans += p * (a ^ b) * .5;
			}
		}
		return ans;
	}
};
