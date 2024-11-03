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

  // int t = 1;
  // cin >> t;
  // while (t--) {
  solve();
  // }
  return 0;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vi v(n);
  rep(i, 0, n) { cin >> v[i]; }

  ll sum = 0;
  rep(i, 0, n) sum += v[i]; // Initialize sum of array elements

  ll last = -1; // This will store the value if a type 2 query is made
  unordered_map<int, ll>
      modified; // To keep track of individual updates after a type 2 query

  rep(i, 0, q) {
    int t;
    cin >> t;

    if (t == 1) {
      // Update a single element
      int in;
      cin >> in;
      ll x;
      cin >> x;
      --in; // Convert to 0-based index

      // If type 2 query has been made before, the original value is `last`,
      // else it's v[in]
      ll original_value =
          (last == -1 || modified.find(in) != modified.end()) ? v[in] : last;

      // Update the sum and store the new value in the array
      sum = sum - original_value + x;
      v[in] = x;        // Store the updated value
      modified[in] = x; // Mark this index as modified after a type 2 query

      cout << sum << endl;
    } else if (t == 2) {
      // Update the entire array with the same value
      ll x;
      cin >> x;

      // Set the new sum
      sum = x * n;

      // Mark that the array is now considered as all `x`
      last = x;
      modified.clear(); // Clear individual updates
      cout << sum << endl;
    }
  }
}

/*
Author: Uttam Raj
Date: 2024-10-13
Problem: Problem Name/URL
*/
