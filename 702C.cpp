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

bool check(int r, vector<int> &c, vi &t, int n, int m);
// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}

bool check(int r, vector<int> &c, vi &t, int n, int m) {
  rep(i, 0, n) {
    int low = 0;
    int high = m - 1;
    int mid;
    bool covered = false;
    while (low <= high) {
      mid = (low + high) / 2;
      // debug(low, mid, high);
      if (t[mid] - c[i] < -r)
        low = mid + 1;
      else if (t[mid] - c[i] > r)
        high = mid - 1;
      else {
        covered = true;
        break;
      }
    }
    if (!covered)
      return false;
  }
  return true;
}
void solve() {
  // Solution
  // Start coding here
  int n, m;
  cin >> n >> m;
  vi c(n);
  vi t(m);
  rep(i, 0, n) cin >> c[i];
  rep(i, 0, m) cin >> t[i];
  int low = 0;
  int high = 2 * 1e9;
  int mid;
  while (low + 1 < high) {
    mid = (high - low) / 2 + low;
    // debug(low, mid, high);
    if (check(mid, c, t, n, m))
      high = mid;
    else
      low = mid + 1;
  }
  // cout << check(2, c, t);
  if (check(low, c, t, n, m))
    cout << low << endl;
  else
    cout << high << endl;
}

/*
Author: Uttam Raj
Date: 2024-12-11
Problem: Problem Name/URL
*/
