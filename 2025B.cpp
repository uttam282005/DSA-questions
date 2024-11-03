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
#define sorta(arr) sort(begin(arr), end(arr))

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

ll powm(ll x, ll n) {
  if (n == 0)
    return 1;
  ll p = powm(x, n / 2);
  if (n & 1)
    return (x * p * p) % MOD;
  return (p * p) % MOD;
}

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // int t = 1;
  // cin >> t;
  // while (t--) {
  solve();
  // }
  return 0;
}
void solve() {
  int t;
  cin >> t;
  vll n(t);
  vll k(t);
  rep(i, 0, t) cin >> n[i];
  rep(i, 0, t) cin >> k[i];
  rep(i, 0, t) { cout << powm(2, k[i]) << endl; }
}

/*
Author: Uttam Raj
Date: 2024-10-14
Problem: Problem Name/URL
*/
