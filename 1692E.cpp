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
  int n, s;
  cin >> n >> s;
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  int l = 0, r = n - 1;
  int prevl = 0, prevr = n - 1;
  vi prefix(n);
  prefix[0] = v[0];
  rep(i, 1, n) { prefix[i] = prefix[i - 1] + v[i]; }
  int ans = 0;
  if (prefix[n - 1] == s) {
    cout << 0 << endl;
    return;
  }
  while (l <= r) {
    if (prefix[r] - prefix[l] + v[l] == s) {
      cout << ans << endl;
      return;
    }
    if (v[l] == 1) {
      ans += l - prevl + 1;
      r = prevr;
      prevl = l + 1;
      l++;
    } else if (v[r] == 1) {
      ans += prevr - r + 1;
      l = prevl;
      prevr = r - 1;
      r--;
    } else {
      l++;
      r--;
    }
  }
  cout << -1 << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-30
Problem: Problem Name/URL
*/
