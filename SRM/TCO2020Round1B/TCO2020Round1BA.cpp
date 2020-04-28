#include <bits/stdc++.h>

using namespace std;

class EllysCandies {
	public:
	string getWinner(vector <int> a) {
		int n = a.size();

		if(n & 1) {
			return "Elly";
		} else {
			return "Kris";
		}
	}
	
};
