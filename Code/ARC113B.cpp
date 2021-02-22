#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll phi(ll n)
{
    ll i,rea=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            rea=rea-rea/i;
            while(n%i==0)
                n/=i;
         }
    }
    if(n>1)
        rea=rea-rea/n;
    return rea;
}

long long power(long long x, long long t, long long P) {
    long long ret = 1;
    for (; t; t >>= 1, x = x * x % P) {
        if (t & 1) {
            ret = ret * x % P;
        }
    }
    return ret;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a %= 10;
    if (a == 0) {
        cout << 0 << '\n';
        exit(0);
    }
    int cur = a;
    map<int, int> vis;
    vector<int> loop;
    while (true) {
        if (vis[cur]) {
            break;
        }
        vis[cur] = 1; 
        loop.emplace_back(cur);
        cur = cur * a % 10;
    }
    int m = loop.size();
    long long x = power(b, c, m);
    cout << loop[(x - 1 + m) % m] << '\n';
    return 0;
}
