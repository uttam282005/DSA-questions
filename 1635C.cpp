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
  int n;
  cin >> n;
  vll v(n);
  int prev = INT_MIN;
  bool isSorted = true;
  rep(i, 0, n) {
    cin >> v[i];
    if (v[i] < prev)
      isSorted = false;
    prev = v[i];
  }
  if (isSorted) {
    cout << 0 << endl;
    return;
  }
  if (v[n - 2] > v[n - 1] || (v[n - 1] < 0 && v[n - 2] < 0)) {
    cout << -1 << endl;
    return;
  }
  int p = v[n - 1];
  int m = 0;
  vector<vector<int>> op;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] > v[i + 1]) {
      m++;
      vi temp(3);
      temp[0] = i + 1;
      temp[1] = i + 2;
      temp[2] = n;
      op.push_back(temp);
      v[i] = v[i + 1] - p;
    }
  }
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    rep(j, 0, 3) { cout << op[i][j] << " "; }
    cout << endl;
  }
}

/*
Author: Uttam Raj
Date: 2024-10-10
Problem: Problem Name/URL
*/
