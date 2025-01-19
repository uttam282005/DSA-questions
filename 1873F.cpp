#include <bits/stdc++.h>
#include <climits>
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

bool good(int len, vi &a, vi &h, int max_sum) {
  int current_len = 0;
  ll sum = 0;
  ll min_sum = INT_MAX;
  int n = h.size();
  rep(i, 0, n) {
    sum += a[i];
    current_len++;
    if (current_len == len) {
      min_sum = min(min_sum, sum);
    }
    if (current_len > len) {
      sum -= a[i - len];
      current_len--;
    }
    if (current_len == len) {
      min_sum = min(min_sum, sum);
    }
    if (i != n - 1 && h[i] % h[i + 1] != 0) {
      sum = 0;
      current_len = 0;
    }
  }
  return min_sum <= max_sum;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, 0, n) cin >> a[i];
  vi h(n);
  rep(i, 0, n) cin >> h[i];
  int low = 0;
  int high = n;
  int mid;
  int ans = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    if (good(mid, a, h, k)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-04
Problem: Problem Name/URL
*/
