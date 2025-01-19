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
  int n, m;
  cin >> n >> m;
  int p_t = 0, p_b = 0, p_l = 0, p_r = 0;
  int ans = n * m * 4;
  rep(i, 0, n) {
    int xi = 0, yi = 0;
    cin >> xi >> yi;

    int n_b = p_b + yi;
    int n_t = m + n_b;
    int n_l = p_l + xi;
    int n_r = n_l + m;
    int w_o = p_r - n_l;
    int h_o = p_t - n_b;
    int m = 2 * (w_o + h_o);
    if (m >= 0)
      ans -= m;
    p_t = n_t;
    p_b = n_b;
    p_l = n_l;
    p_r = n_r;
  }
  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-17
Problem: Problem Name/URL
*/
