#include <bits/stdc++.h>
using namespace std;

// Defines
#define db double
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define itr(container) for (auto &it : container)
#define ss second
#define gcd(a, b) __gcd(a, b)
#define vs vector<string>
#define um unordered_map
#define pb push_back
#define umii unordered_map<int, int>
#define sortv(arr) sort(arr.begin(), arr.end())

// Typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const int N = 1e7 + 1;

// Factorials and Modular Arithmetic
int fact[N];
int inv_fact[N];

// Binary Exponentiation
ll binPow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binPow(a, b / 2);
  res = (res * res) % MOD;
  if (b % 2 == 1)
    res = (res * (a % MOD)) % MOD;
  return res;
}

// Precomputing factorials and inverse factorials

void calculate_factorial_bulk() {
  fact[0] = 1; // Initialize factorial of 0
  for (int i = 1; i <= N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % MOD; // Modular multiplication
  }
  inv_fact[N] = binPow(fact[N], MOD - 2) % MOD; // Modular inverse of fact[N]
  for (int i = N - 1; i >= 0; i--) {
    inv_fact[i] =
        1LL * inv_fact[i + 1] * (i + 1) % MOD; // Modular multiplication
  }
}

// Calculate factorial for small numbers
ll factorialSmall(int n) {
  if (n == 0 || n == 1)
    return 1;
  ll res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}

// nCr calculation with modular arithmetic

ll nCr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  return (1LL * (fact[n]) * (inv_fact[r] % MOD) * (inv_fact[n - r] % MOD)) %
         MOD; // Apply modulo at each step
}

// Combination without modular arithmetic
ll c(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  ll res = 1;
  for (int i = 1; i <= r; i++) {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}

// Derangement Calculation
ll derangements(int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 0;
  ll D = 0;
  ll sign = 1;
  for (int k = 0; k <= n; k++) {
    ll term = (sign * inv_fact[k]) % MOD;
    term = (term + MOD) % MOD;
    term = (term * fact[n]) % MOD;
    D = (D + term) % MOD;
    sign *= -1;
  }
  return D;
}

// Debug Function
#define debug(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void _f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void _f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << arg1 << "|";
  _f(comma + 1, args...);
}

// Function to calculate prefix sum of an array
vector<ll> prefixSum(const vector<ll> &arr) {
  int n = arr.size();
  vector<ll> psum(n);
  psum[0] = arr[0];
  for (int i = 1; i < n; i++) {
    psum[i] = psum[i - 1] + arr[i];
  }
  return psum;
}

// Function prototypes
void solve();

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  calculate_factorial_bulk();
  solve();
  return 0;
}
// const int MOD = 1e9 + 7;
// const int MOD = 998244353;
// const long long MOD = 1375927501846395853LL;
struct Mint {
  int val;

  Mint(long long v = 0) {
    if (v < 0)
      v = v % MOD + MOD;
    if (v >= MOD)
      v %= MOD;
    val = v;
  }

  static int mod_inv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  Mint &operator+=(const Mint &other) {
    val += other.val;
    if (val >= MOD)
      val -= MOD;
    return *this;
  }
  Mint &operator-=(const Mint &other) {
    val -= other.val;
    if (val < 0)
      val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  Mint &operator*=(const Mint &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  Mint &operator/=(const Mint &other) { return *this *= other.inv(); }
  friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
  friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
  friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
  friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
  Mint &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  Mint &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  // friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <=
  // (int)b; }
  Mint operator++(int32_t) {
    Mint before = *this;
    ++*this;
    return before;
  }
  Mint operator--(int32_t) {
    Mint before = *this;
    --*this;
    return before;
  }
  Mint operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const Mint &other) const { return val == other.val; }
  bool operator!=(const Mint &other) const { return val != other.val; }
  Mint inv() const { return mod_inv(val); }
  Mint power(long long p) const {
    assert(p >= 0);
    Mint a = *this, result = 1;
    while (p > 0) {
      if (p & 1)
        result *= a;
      a *= a, p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &stream, const Mint &m) {
    return stream << m.val;
  }
  friend istream &operator>>(istream &stream, Mint &m) {
    return stream >> m.val;
  }
};
struct Comb {
  int n;
  vector<Mint> _fac, _invfac, _inv;
  Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
  Comb(int n) : Comb() { init(n); }
  void init(int m) {
    m = min(m, MOD - 1);
    if (m <= n)
      return;
    _fac.resize(m + 1);
    _invfac.resize(m + 1);
    _inv.resize(m + 1);
    for (int i = n + 1; i <= m; i++)
      _fac[i] = _fac[i - 1] * i;
    _invfac[m] = _fac[m].inv();
    for (int i = m; i > n; i--)
      _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
    n = m;
  }
  Mint fac(int m) {
    if (m > n)
      init(2 * m);
    return _fac[m];
  }
  Mint invfac(int m) {
    if (m > n)
      init(2 * m);
    return _invfac[m];
  }
  Mint inv(int m) {
    if (m > n)
      init(2 * m);
    return _inv[m];
  }
  Mint ncr(int n, int r) {
    if (n < r || r < 0)
      return 0;
    return fac(n) * invfac(r) * invfac(n - r);
  }
} comb;

void solve() {
  int n;
  cin >> n;
  int N = n + 1;
  int K = n - 1;

  Mint x = comb.ncr(2 * n - 1, n);
  cout << 2 * x - n << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-26
Problem: Problem Name/URL
*/
