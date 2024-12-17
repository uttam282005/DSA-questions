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
// bool f(ll odd_sum, ll even_sum, int l, int r, vector<int> v) {
//   if (l >= r)
//     return false;
//   if (odd_sum == even_sum)
//     return true;
//   if (odd_sum > even_sum) {
//     if ((l + 1) & 1 && (r + 1) & 1) {
//       return f(odd_sum - v[l], even_sum, l + 1, r, v);
//       return f(odd_sum - v[r], even_sum, l, r - 1, v);
//     } else if ((l + 1) & 1)
//       return f(odd_sum - v[l], even_sum, l + 1, r, v);
//     else if ((r + 1) & 1)
//       return f(odd_sum - v[r], even_sum, l, r - 1, v);
//     else
//       return false;
//   } else {
//     if (!((l + 1) & 1) && !((r + 1) & 1)) {
//       return f(odd_sum, even_sum - v[l], l + 1, r, v);
//       return f(odd_sum, even_sum - v[r], l, r - 1, v);
//     } else if (!((l + 1) & 1))
//       return f(odd_sum, even_sum - v[l], l + 1, r, v);
//     else if (!((r + 1) & 1))
//       return f(odd_sum, even_sum - v[r], l, r - 1, v);
//     else
//       return false;
//   }
// }

void solve() {
  int n;
  cin >> n;
  vi v(n + 1);
  vll diff(n);
  ll prefix_odd = 0;
  ll prefix_even = 0;
  rep(i, 1, n + 1) {
    cin >> v[i];
    if (i & 1)
      prefix_odd += v[i];
    else
      prefix_even += v[i];
    diff[i - 1] = prefix_odd - prefix_even;
  }
  sort(diff.begin(), diff.end());
  if (diff[0] == 0) {
    cout << "YES\n";
    return;
  }
  rep(i, 1, n) {
    if (diff[i] == diff[i - 1] || diff[i] == 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
/*
Author: Uttam Raj
Date: 2024-11-08
Problem: Problem Name/URL
*/
