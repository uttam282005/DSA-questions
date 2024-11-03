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

void solve() {
  // Solution
  // Start coding here
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> cards(m, vector<ll>(n));
  rep(i, 0, n) {
    rep(j, 0, m) { cin >> cards[j][i]; }
  }

  rep(i, 0, m) sort_vec(cards[i]);
  vector<ll> column_wise_prefix;
  rep(i, 0, m) {
    ll prefix = 0;
    rep(j, 0, n) { prefix += cards[i][j]; }
    column_wise_prefix.pb(prefix);
  }
  ll ans = 0;
  rep(i, 0, m) {
    ll prefix = 0;
    rep(j, 0, n) {
      prefix += cards[i][j];
      ans += ((column_wise_prefix[i] - prefix) - (cards[i][j] * (n - j - 1)));
    }
  }
  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-27
Problem: Problem Name/URL
*/
