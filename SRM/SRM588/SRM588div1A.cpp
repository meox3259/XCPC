#include <bits/stdc++.h>

using namespace std;

class GUMIAndSongsDiv1 {
	public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int n = tone.size();
		vector<pair<int, int> > song;

		for(int i = 0; i < n; ++i) {
			song.emplace_back(tone[i], duration[i]);	
		}

		sort(song.begin(), song.end());

		int ans = 0;

		for(int i = 0; i < n; ++i) {
			for(int j = i; j < n; ++j) {
				int l = song[i].first;
				int r = song[j].first;
				int rem = T - (r - l);
				vector<int> t;
				for(auto o : song) {
					int x = o.first;
					int y = o.second;
					if(l <= x && x <= r) {
						t.emplace_back(y);
					}
				}
				sort(t.begin(), t.end());
				int tmp = 0;
				for(int x : t) {
					if(rem >= x) {
						rem -= x;
						tmp += 1;
					}
				}
				ans = max(ans, tmp);
			}
		}
		
		return ans;
	}
};
