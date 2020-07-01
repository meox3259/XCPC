// BEGIN CUT HERE
// END CUT HERE
#line 4 "ColorfulBuilding.cpp"
#include <bits/stdc++.h>

using namespace std;

const int P = 1000000009;

class ColorfulBuilding {
	public:
	long long power(long long x, long long t) {
		long long ret = 1;
		for(; t; t >>= 1, x = x * x % P) {
			if(t & 1) {
				ret = ret * x % P;
			}
		}
		return ret;
	}

	int count(vector <string> color1, vector <string> color2, int L) {
		string s = "";
		for(auto o : color1) {
			s += o;
		}

		string t = "";
		for(auto o : color2) {
			t += o;
		}

		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());

		s += '#';
		t += '#';

		int n = s.size();
		int tot = 0;
		map<pair<char, char>, int> id;
		for(int i = 0; i < n; ++i) {
			id[{s[i], t[i]}] = tot++;
		}
	
		vector<vector<long long> > dp(n + 1, vector<long long> (n + 1));
		vector<vector<long long> > pre(n + 1, vector<long long> (n + 1));
		vector<long long> sum(n + 1);
		dp[1][1] = 1;
		sum[1] = 1;
		pre[id[{s[0], t[0]}]][1] = 1;

		for(int i = 1; i < n; ++i) {
			int c = id[{s[i], t[i]}];
			long long inv = power(i, P - 2);
			for(int j = 0; j < n; ++j) {
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (sum[j] - pre[c][j] + pre[c][j + 1]) * inv % P + P) % P;
			}
			for(int j = 0; j <= n; ++j) {
				sum[j] = (sum[j] + dp[i + 1][j]) % P;
			}
			for(int j = 0; j <= n; ++j) {
				pre[c][j] = (pre[c][j] + dp[i + 1][j]) % P;
			}
		}
		
		long long ans = dp[n][L + 1];
		for(int i = 1; i < n; ++i) {
			ans = ans * i % P;
		}

		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"aaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"aaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 0; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"ab", "ba", "a", "aab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bb", "ba", "a", "aba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 432; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; int Arg3 = 619787617; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"SJXcabKTWeUXhwxGixFepQaQlFxrAedNAtVP",
 "gorBIkcTlOFbLDbFeElYAyAqszQdMbpxSRdE",
 "SQVHPehlNtesbJDflyGxMqvgzjXisRnqDcQO",
 "pIAEBwbmpPWCooQAujbGXFGLvXxTmExLARkf",
 "AFnWyWKVObfxDGCjTxdZaObgwdxlPKtIxaAd",
 "uznMpJVNjAofbHJjOrZeSHgSagOCUMGbvkVR",
 "LBRrDbTAyKfVnedKiRfzgRzECpcsziqaTwdo",
 "JrJHvsEVVGDkNVGqLbpxyLDPloBuNDQKnReI",
 "SSYpbjKHSCnQhuyYrVauWDHDyhAoGyecrZMv",
 "UdetQfWEUWHHuAxRSdkJOOJSixKpQXpCFZHO",
 "KXVsQbuQtIgsULOMsTvPFNUqkBldMTLCipYK",
 "hoXConjnDWQkZVtyZlwSedvdVrNWqQhGUClQ",
 "TpsvvyoXsXmQpBAGGVDrXCkodoRHQZmpoQDW",
 "csiJspzTqeFBRmPgeEtTAzfrfCGlTZqcPuyO",
 "vsPDVBJVaJmUAtDdcsKoUkPEbDmAwtZKwjjP",
 "MOfoMhMiKIvGQoeIJXHzyClWRtRuKXMqxUAF",
 "KyyUCkRBjsYvmPFFEGBqqVhIUdtvIyyLacfu",
 "BfuwfSajSlcuTzhMufHSQLudvGEGlyHsEmBD",
 "PLpIXZkdyXveTMfSvqnDGKWOZrTBMUIlZrqF",
 "dzVMCqrSLbanRJTYpDJNHAOLPSzmvSEPQJYm",
 "rAjRkrSjouJyFaCSPPLYSzqDmMoADyWAbobJ",
 "eOCBrJNoyFnGpXpxiExXcoOHnVsaEPXhPfLe",
 "XMjRksnxWssPEINhdhbiLBSYpCLtwNshFjXS",
 "HnnDeUAbuswsgsYQuAaXySLkFYUwFXwYTreM",
 "uqLnwOEGbwZZDgAAWEdLRZxFlogDmlhjhgHM",
 "NcfaQsgPQfirkYDRFrLQpySmBGfRHumKULZf",
 "mOpmmgclsxRzXskEywfryqCRyATNoJwnlHiD",
 "AnoKoKAjrasttjNlHCROnvTJMhEHlVPVoVMo",
 "yegLyIuRkkENFAjwzDoPLKjgUHHEkfzYDIpo",
 "EcxRGGfuaBXUFXkSxctJWOLmmVbvoMkWtTvV",
 "nBMkOBHgaltEVzfyGxseGhmBscfGIbxFbqRn",
 "GvkEcLtqdOofGtsbWDafVMbNdJxsffKDzSiR",
 "jhZQUVzTzalrZcebvyqPWtOUUyniBKTWdyLi",
 "ODJLQPMdjDdTlxrfGsNmBfeGYjzeXApqKDhJ",
 "vlJkWMzdVQujKdLViQClOrJXMTBkuZEasFgg",
 "FAsbuzrLVIgaryqXBfuBRAbReleXSSgEKSvt"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"XAhlUHtfjOpOlQlowWppQcodMGUiqoLobxnD",
 "IDzGlKrHiVGdBjZxIcoxjwagbWieKvUwZrjg",
 "SkpkTVeIFeoNQzUUgmYAYskKONNZdgXxSiWd",
 "rXBGhTmqnvxkmqiutoDzPusDiOUggEFXGCzm",
 "fzrxVuTbFXunGbeEavjshmrIRlDorTuISCxn",
 "LsvIaxTkOBjcskiekmrKNNFEXqnfMNXLWqqu",
 "ekzxGIlbJPVEQPYAbTuMtZKsCiubDXDiBVzU",
 "hZuOCJxvBOYENGSFcUiKKAKfCdebutVmnyvB",
 "UveNkKRQmHnedrROQOpHJfrHjwcNLUShlDbn",
 "ptUkvbaGDryHRkYfHKLkSgVpjWCEcgazyxGK",
 "nVPYEqTTJsRPjzjfdOiULhnZPFeNcnbXaQlk",
 "IPXBXRhMQIkxpygsgbcRfMuvIcuzUPPHGOWX",
 "yWWlNyEyqZSIOXBFAybIuFpVqpvmKRaRFrAE",
 "EvBJVtHvKhjrFcmtpdBbFTdTVtXXZQKAglKT",
 "bCVjHzUvyINFkxXageZQMzCyNhcifACdJVDh",
 "lZITYcDSeIbLweyFtoMAfOQyBNupKlhcNpgo",
 "BduslNrJdWOUukYFFidEkMFaghfofpxVgvJd",
 "YrJpDZKqdjEPzdLsOQEdkcrBfNHPemXHokCW",
 "GjeUKSGjDlgKTyUGNrMQbBLxRUcgrWpkAwOD",
 "wgxTcswqdJHaDugNIRMvrhBsdDaJAssVbSRW",
 "qmVmqFEpvgGioMXDSFqEoQcDOAaUoGPEovSO",
 "KrukPlpfOhawaovCfteTSCIdLMrtImVtiMyQ",
 "ykwmxHsKMFzFHwcbyyedLvhZPnaNGqJMMCxd",
 "HUNYCXjNLQIFCLLGpCXHBCHLTxLynBxnHFbx",
 "uwjzbNbJepVFgMPUXVirxYHzExquBEtPmKju",
 "xXAxAbJePyUsVHeLytDvAxBGMRtnvCEiZZqe",
 "xMkQoIVxWPXPgaOYmDjTOXiMImVdzojERNxS",
 "dwICFwMAmdOIUxyAdXdshasnzwyhfnVWVqZJ",
 "etypXNVvSTEQvriGBZdSGmDEHhvpSqkFklCS",
 "YkxpFBCRYUueRcKaJUXVdaMoYMYEooPQVMOr",
 "DTrexDqclZNKdPuTRFHualJSFziCLPCZjpxo",
 "TfEijcAsSJPikkmBSbXMqYHAhPTcpcKVSkIX",
 "xKXHYPYMJxFpSbxltDKYuRiTkOLxpQKnXZPs",
 "YFYuvuYHfpFJcrLNIdlNfBxRnWdppsdalBkx",
 "NFTysBvNFjejdnlhRTclbcfGipNCxpFEOriY",
 "thkgVflJYmbUYbIlafNUMGePQWiZyYzYXvUR"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1200; int Arg3 = 396065426; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};
// BEGIN CUT HERE
int main()  {  
ColorfulBuilding ___test;  
___test.run_test(-1);    
}  
// END CUT HERE
