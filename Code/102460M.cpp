#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max();
long long modpow(long long x, long long y, long long mod) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      ret = ret * x % mod;
    }
  }
  return ret;
}

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
}  // namespace internal

// (rem, mod)
std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    // Contracts: 0 <= r0 < m0
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % m1 = r1
        // -> (r0 + x*m0) % m1 = r1
        // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)
        // -> x = (r1 - r0) / g * inv(u0) (mod u1)

        // im = inv(u0) (mod u1) (0 <= im < u1)
        long long g, im;
        std::tie(g, im) = internal::inv_gcd(m0, m1);

        long long u1 = (m1 / g);
        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
        if ((r1 - r0) % g) return {0, 0};

        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
        long long x = (r1 - r0) / g % u1 * im % u1;

        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * m1 / g - m0
        // = lcm(m0, m1)
        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

int main() {
  long long n, m;
  int d;
  cin >> n >> m >> d;
  vector<tuple<int, int, int>> fact;
  int x = d;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      int mul = 1;
      int cnt = 0;
      while (x % i == 0) {
        x /= i;
        mul *= i;
        cnt ++;
      }
      fact.emplace_back(i, mul, cnt);
    }
  }
  if (x > 1) {
    fact.emplace_back(x, x, 1);
  }
  auto f = [&] (long long n, int p) -> long long {
    long long ret = 0;
    while (n) {
      ret += n / p;
      n /= p;
    }
    return ret;
  };
  auto calc = [&] (int p) -> long long {
    return f(n, p) - f(m, p) - f(n - m, p);
  };
  long long k = inf;
  for (auto [p, v, cnt] : fact) {
    k = min(k, calc(p) / cnt);
  }
  vector<long long> a;
  vector<long long> mod;
  for (auto [p, v, cnt] : fact) {
    vector<long long> dp(v + 1);
    dp[0] = 1;
    for (int i = 1; i <= v; ++i) {
      dp[i] = dp[i - 1];
      if (i % p != 0) {
        dp[i] *= i;
        dp[i] %= v;
      }
    }
    auto dfs = [&] (auto &&f, long long n, int p, int v) -> long long {
      if (n == 0) {
        return 1;
      } 
      return f(f, n / p, p, v) * modpow(dp[v], n / v, v) % v * dp[n % v] % v;
    };
    auto inv = [&] (long long a, long long b) -> long long {
      auto [m0, m1] = internal::inv_gcd(a, b);
      return m1;
    };
    a.push_back(modpow(p, calc(p) - k * cnt, v) * dfs(dfs, n, p, v) % v * inv(dfs(dfs, m, p, v), v) % v * inv(dfs(dfs, n - m, p, v), v) % v * inv(modpow(d / v, k, v), v) % v);
    mod.push_back(v); 
  }
  auto [ans, g] = crt(a, mod);
  cout << ans << '\n';
}
