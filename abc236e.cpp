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
db checker(vector<db> v, db avg, int n) {
  vector<db> d(n);
  d[0] = v[0];
  d[1] = v[1] + max(d[0], db(0));
  rep(i, 2, n) { d[i] = v[i] + max(d[i - 1], d[i - 2]); }
  return max(d[n - 1], d[n - 2]);
}
void solve() {
  int n;
  cin >> n;
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  db low = 0;
  db high = 1e9;
  db mid;
  db avg;
  db error = 1e-4;
  rep(i, 0, 100) {
    mid = (low + high) / 2;
    vector<db> t(n);
    rep(i, 0, n) t[i] = v[i] - mid;
    if (checker(t, mid, n) >= 0) {
      avg = mid;
      low = mid + error;
    } else {
      high = mid - error;
    }
  }
  ll l = 0;
  ll h = 1e9;
  ll mid2;
  ll median;

  while (l <= h) {
    mid2 = (l + h) / 2;
    vector<db> m(n);
    rep(i, 0, n) m[i] = (v[i] >= mid2 ? 1 : -1);
    if (checker(m, mid2, n) > 0) {
      median = mid2;
      l = mid2 + 1;
    } else {
      h = mid2 - 1;
    }
  }

  cout << avg << " " << median;
}

/*
Author: Uttam Raj
Date: 2024-12-17
Problem: Problem Name/URL
*/