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
  vi v(n);
  map<int, int> cnt;
  rep(i, 0, n) {
    cin >> v[i];
    cnt[v[i]]++;
  }
  vi unique;
  sort(all(v));
  unique.push_back(v[0]);
  rep(i, 1, n) {
    if (unique.back() != v[i])
      unique.push_back(v[i]);
  }
  int p = unique.size();
  ll ans = 0;
  ll com = 1;

  auto mod_inverse = [](ll a, ll mod) {
    ll res = 1, exp = mod - 2;
    while (exp > 0) {
      if (exp % 2 == 1)
        res = (res * a) % mod;
      a = (a * a) % mod;
      exp /= 2;
    }
    return res;
  };
  if (m > p) {
    cout << 0 << endl;
    return;
  }
  rep(i, 0, m) { com = (com * cnt[unique[i]] * 1ll) % MOD; }
  if (unique[m - 1] - unique[0] < m) {
    ans += com;
  }
  rep(i, m, p) {
    com = (com * cnt[unique[i]] * 1ll) % MOD;
    // Replace division with modular inverse
    com = (com * mod_inverse(cnt[unique[i - m]], MOD)) % MOD;
    if (unique[i] - unique[i - m + 1] < m) {
      ans += com % MOD;
    }
  }

  cout << ans % MOD << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-09
Problem: Problem Name/URL
*/
