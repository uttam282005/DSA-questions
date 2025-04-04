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
ll cost(int k, vll v, int n, int s) {
  ll total_cost = 0;
  rep(i, 0, n) v[i] = v[i] + 1ll * k * (i + 1);
  sort(all(v));
  rep(i, 0, k) total_cost += v[i];
  return total_cost;
}
void solve() {
  int n, s;
  cin >> n >> s;
  vll v(n);
  rep(i, 0, n) cin >> v[i];
  // sort(all(v));
  int low = 0;
  int high = n;
  int mid;
  while (low + 1 < high) {
    mid = (low + high) / 2;
    if (cost(mid, v, n, s) <= s)
      low = mid;
    else
      high = mid - 1;
  }
  if (cost(high, v, n, s) <= s)
    cout << high << " " << cost(high, v, n, s);
  else
    cout << low << " " << cost(low, v, n, s);
}

/*
Author: Uttam Raj
Date: 2024-12-13
Problem: Problem Name/URL
*/
