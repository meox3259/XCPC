#include <bits/stdc++.h>

using namespace std;

class FoxAndFencing {
	public:
	string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
		if(mov1 + rng1 >= d) {
			return "Ciel";
		}

		if(mov2 + rng2 >= d + mov1) {
			return "Liss";
		}

		if(mov1 == mov2) {
			return "Draw";
		}

		if(mov1 > mov2) {
			if(mov1 + rng1 - mov2 > mov2 + rng2) {
				return "Ciel";
			} else {
				return "Draw";
			}
		}

		if(mov2 > mov1) {
			if(mov2 + rng2 - mov1 > mov1 + rng1) {
				return "Liss";
			} else {
				return "Draw";
			}
		}

		return "Draw";
	}
};
