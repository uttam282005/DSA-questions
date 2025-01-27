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

// Debug Function
#define debug(...) _f(#__VA_ARGS__, __VA_ARGS__)

// Sorting Functions
template <typename T> void sort_vec(vector<T> &v) { sort(v.begin(), v.end()); }

template <typename T> void sort_desc(vector<T> &v) {
  sort(v.begin(), v.end(), greater<T>());
}

// Debug function definitions
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

const int N = 1e5 + 1;

int fact[N + 1];
int inv_fact[N + 1];

ll binPow(ll a, ll b) {
  if (b == 0)
    return 1;                // Base case: anything to the power of 0 is 1
  ll res = binPow(a, b / 2); // Recursive step
  res = (res * res) % MOD;   // Square the result and take modulo
  if (b % 2 == 1)
    res = (res * (a % MOD)) % MOD; // If b is odd, multiply by 'a'
  return res;
}

// Time Complexity = O(max_n)
void calculate_factorial_bulk() {
  fact[0] = 1;

  for (int i = 1; i <= N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % MOD;
  }

  inv_fact[N] = binPow(fact[N], MOD - 2) % MOD;
  for (int i = N - 1; i >= 0; i--) {
    inv_fact[i] = 1ll * inv_fact[i + 1] * (i + 1) % MOD;
  }
};

// Time Complexity = O(r)
ll c(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  ll res = 1;
  for (int i = 1; i <= r; i++) {
    res *= n - i + 1;
    res /= i;
  }
  return res % MOD;
}

ll nCr(int n, int r) {
  if (r < 0 || r > n)
    return 0;
  return 1ll * fact[n] * inv_fact[r] * inv_fact[n - r] % MOD;
}

void solve() {}

/*
Author: Uttam Raj
Date: 2025-01-22
Problem: Problem Name/URL
*/
