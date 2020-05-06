#include <bits/stdc++.h>

using namespace std;

class TaskA {
	public:
		void solveOne(istream &in, ostream &out) {
			int a, b, c, d, k;
			in >> a >> b >> c >> d >> k;
			int pen = (a + c - 1) / c;
			int pencil = (b + d - 1) / d;
			if(pen + pencil > k) {
				out << -1 << '\n';
			} else {
				out << pen << ' ' << pencil << '\n';
			}
		}

		void solve(std::istream &in, std::ostream &out) {
			int kase;
			in >> kase;
			for(int i = 0; i < kase; ++i) {
				solveOne(in, out);
			}
		}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
