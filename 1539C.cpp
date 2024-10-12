#include <bits/stdc++.h>
#include <climits>
using namespace std;

// Defines
#define db double
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define itr(container) for (auto &it : container)
#define ss second
#define gcd(a, b) __gcd(a, b)
#define vs vector<string>
#define um unordered_map
#define umii unordered_map<int, int>
#define sorta(arr) sort(begin(arr), end(arr))
#define sortv(vec) sort(vec.begin(), vec.end())

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
template <typename T> void sort_asc(vector<T> &v) { sort(v.begin(), v.end()); }

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

  // int t = 1;
  // cin >> t;
  // while (t--) {
  solve();
  // }
  return 0;
}

void solve() {
  // Solution
  // Start coding here
  ll n, k, x;
  cin >> n >> k >> x;
  vll v(n);
  rep(i, 0, n) cin >> v[i];
  sort_asc(v);
  int groups = 1;
  vll b;
  rep(i, 0, n - 1) {
    if (v[i + 1] - v[i] > x)
      b.pb(v[i + 1] - v[i]);
  }

  sort_asc(b);
  ll cnt = -1;
  rep(i, 0, b.size()) {
    if (k == 0) {
      cnt = i;
      break;
    }
    if (b[i] % x == 0) {
      k -= (b[i] / x - 1);
      if (k < 0) {
        cnt = i;
        break;
      }
    } else {
      k -= (b[i] / x);
      if (k < 0) {
        cnt = i;
        break;
      }
    }
  }
  if (cnt == -1) {
    cout << 1 << endl;
    return;
  }
  cout << b.size() - cnt + 1 << endl;
  return;
}

/*
Author: Uttam Raj
Date: 2024-10-07
Problem: Problem Name/URL
*/
