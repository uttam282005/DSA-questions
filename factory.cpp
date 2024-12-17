#include <algorithm>
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

  solve();
  return 0;
}
bool possible(ll time, vll &v, int t) {
  ll machines_made = 0;
  rep(i, 0, v.size()) {
    machines_made += (time / v[i]);
    if (machines_made >= t)
      return true;
  }
  return machines_made >= t;
}
void solve() {
  int n;
  int t;
  cin >> n >> t;
  vll v(n);
  rep(i, 0, n) cin >> v[i];
  ll l = 0;
  ll r = 1e18;
  ll mid;
  while (l + 1 < r) {
    mid = (r - l) / 2 + l;
    if (possible(mid, v, t))
      r = mid;
    else
      l = mid + 1;
  }
  if (possible(l, v, t))
    cout << l << endl;
  else
    cout << r << endl;
}

/*
Author: Uttam Raj
Date: 2024-12-08
Problem: Problem Name/URL
*/
