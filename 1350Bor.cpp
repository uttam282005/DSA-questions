#include <bits/stdc++.h>
#include <climits>
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
const int N = 1e5;

// Factorials and Modular Arithmetic
int fact[N + 1];
int inv_fact[N + 1];

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
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % MOD;
  }
  inv_fact[N] = binPow(fact[N], MOD - 2) % MOD;
  for (int i = N - 1; i >= 0; i--) {
    inv_fact[i] = 1ll * inv_fact[i + 1] * (i + 1) % MOD;
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
  return 1ll * fact[n] * inv_fact[r] * inv_fact[n - r] % MOD;
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

ll gcd(ll a, ll b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(ll a, ll b, ll *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  ll x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
} // pass an arry of size1 3
ll mminv(ll a, ll b) {
  ll arr[3];
  extendgcd(a, b, arr);
  return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {
  ll val1 = fact[n];
  ll val2 = ifact[n - r];
  ll val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n) {
  int *arr = new int[n + 1];
  vector<ll> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}
ll mod_add(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n) {
  ll number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0)
      n /= 2;
  }
  for (ll i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1)
    number = (number / n * (n - 1));
  return number;
} // O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
struct Hashing {
  string s;
  int n;
  int primes;
  vector<ll> hashPrimes = {1000000009, 100000007};
  const ll base = 31;
  vector<vector<ll>> hashValues;
  vector<vector<ll>> powersOfBase;
  vector<vector<ll>> inversePowersOfBase;
  Hashing(string a) {
    primes = sz(hashPrimes);
    hashValues.resize(primes);
    powersOfBase.resize(primes);
    inversePowersOfBase.resize(primes);
    s = a;
    n = s.length();
    for (int i = 0; i < sz(hashPrimes); i++) {
      powersOfBase[i].resize(n + 1);
      inversePowersOfBase[i].resize(n + 1);
      powersOfBase[i][0] = 1;
      for (int j = 1; j <= n; j++) {
        powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
      }
      inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
      for (int j = n - 1; j >= 0; j--) {
        inversePowersOfBase[i][j] =
            mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
      }
    }
    for (int i = 0; i < sz(hashPrimes); i++) {
      hashValues[i].resize(n);
      for (int j = 0; j < n; j++) {
        hashValues[i][j] =
            ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
        hashValues[i][j] =
            (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) %
            hashPrimes[i];
      }
    }
  }
  vector<ll> substringHash(int l, int r) {
    vector<ll> hash(primes);
    for (int i = 0; i < primes; i++) {
      ll val1 = hashValues[i][r];
      ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
      hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]),
                        inversePowersOfBase[i][l], hashPrimes[i]);
    }
    return hash;
  }
};

// Function prototypes
void solve();

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

void solve() {
  int n;
  cin >> n;
  vll v(n + 1);
  rep(i, 1, n + 1) cin >> v[i];
  vll dp(n + 1, 0);
  dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    ll max_next = 0;
    int j = 2 * i;
    while (j <= n) {
      if (v[j] > v[i])
        max_next = max(max_next, dp[j]);
      j += i;
    }
    dp[i] += max_next + 1;
  }
  sort(all(dp));
  cout << dp[n] << endl;
}

/*
Author: Uttam Raj
Date: 2025-03-18
Problem: Problem Name/URL
*/
