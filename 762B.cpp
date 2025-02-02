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

  solve();
  return 0;
}

const string types[] = {"USB", "PS/2"};
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  vi usb;
  vi ps;
  rep(i, 0, n) {
    int price;
    cin >> price;
    string type;
    cin >> type;
    if (type == types[0]) {
      usb.pb(price);
    } else
      ps.pb(price);
  }
  ll cost = 0;
  sort(all(usb));
  sort(all(ps));
  int u = 0;
  int computers = 0;
  while (u < usb.size() && a != 0) {
    computers++;
    cost += usb[u];
    a--;
    u++;
  }
  int p = 0;
  while (p < ps.size() && b != 0) {
    computers++;
    cost += ps[p];
    b--;
    p++;
  }
  while (u < usb.size() && p < ps.size() && c != 0) {
    computers++;
    if (usb[u] < ps[p]) {
      cost += usb[u];
      u++;
      c--;
    } else {
      cost += ps[p];
      p++;
      c--;
    }
  }
  if (c != 0) {
    while (u < usb.size() && c != 0) {
      computers++;
      cost += usb[u];
      c--;
      u++;
    }
    while (p < ps.size() && c != 0) {
      computers++;
      cost += ps[p];
      c--;
      p++;
    }
  }
  cout << computers << " " << cost << endl;
}

/*
Author: Uttam Raj
Date: 2025-02-02
Problem: Problem Name/URL
*/
