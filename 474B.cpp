#include <algorithm>
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

  solve();
  return 0;
}

void solve() {
  // Solution
  // Start coding here
  int n;
  cin >> n;
  vi p(n);
  rep(i, 0, n) cin >> p[i];
  int m;
  cin >> m;
  vi j(m);
  rep(i, 0, m) cin >> j[i];
  vi prefix_array(n);
  prefix_array[0] = p[0];
  rep(i, 1, n) prefix_array[i] = prefix_array[i - 1] + p[i];
  rep(i, 0, m) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (prefix_array[mid] >= j[i])
        high = mid;
      else
        low = mid + 1;
    }
    cout << low + 1 << endl;
  }
}

/*
Author: Uttam Raj
Date: 2024-12-10
Problem: Problem Name/URL
*/