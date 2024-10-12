#include <bits/stdc++.h>
using namespace std;

// Defines
#define db double
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define itr(container) for (auto &it : container)
#define ss second
#define gcd(a, b) __gcd(a, b)
#define vi vector<ll>
#define vs vector<string>
#define um unordered_map
#define umii unordered_map<int, int>
#define pii pair<int, int>
#define sorta(arr) sort(begin(arr), end(arr))
#define sortv(vec) sort(vec.begin(), vec.end())

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
  vi a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  int ans = 0;
  rep(i, 1, n + 1) {
    for (int j = a[i] - i; j < n + 1; j += a[i]) {
      if (i < j && 1ll * a[i] * a[j] == i + j)
        ans++;
    }
  }
  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-06
Problem: Problem Name/URL
*/
