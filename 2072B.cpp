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
const int N = 1;

unsigned int get_mask(unsigned int n) {
  if (n == 0 || n == 1)
    return 0;

  unsigned int prev = n - 1;
  int high_bit = 31 - __builtin_clz(prev);

  if (n == (1u << high_bit)) {
    return (1u << high_bit) - 1;
  } else {
    return (1u << (high_bit + 1)) - 1;
  }
}

void solve() {
  int n;
  unsigned int x;
  cin >> n >> x;

  int best_m = 0;
  for (int m = 0; m <= n; m++) {
    if (m == 0) {
      best_m = 0;
    } else {
      unsigned int base = get_mask(m);
      if ((base & (~x)) != 0)
        continue;

      int need = (base == x) ? m : m + 1;
      if (need <= n)
        best_m = m;
    }
  }

  vector<unsigned int> vals;
  if (best_m == 0) {
    vals.pb(x);
  } else {
    rep(i, 0, best_m) vals.pb(i);
    unsigned int base = get_mask(best_m);
    if (base != x)
      vals.pb(x & (~base));
  }

  vector<unsigned int> res;
  itr(vals) res.pb(it);

  unsigned int filler = (best_m > 0 ? 0u : x);
  while (res.size() < (size_t)n)
    res.pb(filler);

  itr(res) cout << it << " ";
  cout << "\n";
}

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

/*
Author: Uttam Raj
Date: 2025-02-25
Problem: Problem Name/URL
*/
