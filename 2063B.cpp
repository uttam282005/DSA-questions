#include <bits/stdc++.h>
#include <climits>
#include <numeric>
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

vll prefix_sum(vi v, int n) {
  vll ps(n);
  if (n == 0)
    return {};
  ps[0] = v[0];
  rep(i, 1, n) ps[i] = ps[i - 1] + v[i];
  return ps;
}

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  l--;
  r--;
  vi ls, rs, seg;
  vi v(n);

  rep(i, 0, n) {
    cin >> v[i];
    if (i < l)
      ls.pb(v[i]);
    else if (i >= l && i <= r)
      seg.pb(v[i]);
    else
      rs.pb(v[i]);
  }

  sort(all(seg));
  sort(all(ls));
  sort(all(rs));

  int szl = ls.size();
  int szr = rs.size();
  int s = seg.size();

  ll sum = accumulate(seg.begin(), seg.end(), 0 * 1ll);
  ll ans1 = sum;
  ll ans2 = sum;
  ll current_sum = sum;

  int i = s - 1;
  int j = 0;

  while (i >= 0 && j < szr && rs[j] < seg[i]) {
    current_sum -= seg[i];
    current_sum += rs[j];

    ans1 = min(current_sum, sum);
    i--;
    j++;
  }

  current_sum = sum;
  i = s - 1;
  j = 0;

  while (i >= 0 && j < szl && ls[j] < seg[i]) {
    current_sum -= seg[i];
    current_sum += ls[j];

    ans2 = min(current_sum, sum);
    i--;
    j++;
  }

  ll ans = sum;
  ans = min(ans1, ans2);

  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-22
Problem: Problem Name/URL
*/
