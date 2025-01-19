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

const int N = 200001;
int spf[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < N; i++)
    spf[i] = i;
  for (int i = 2; i < N; i++) {
    for (int j = 2 * i; j < N; j += i) {
      if (spf[j] == j)
        spf[j] = i;
    }
  }

  vi v(n), primes[N];
  rep(i, 0, n) cin >> v[i];
  rep(i, 0, n) {
    while (v[i] != 1) {
      int pf = spf[v[i]];
      int cnt = 0;
      while (v[i] % pf == 0) {
        cnt++;
        v[i] /= pf;
      }
      primes[pf].pb(cnt);
    }
  }
  ll ans = 1;
  for (int i = 1; i < N; i++) {
    sort(primes[i].begin(), primes[i].end());
    if (primes[i].size() < n - 1)
      continue;
    else {
      if (primes[i].size() == n)
        ans *= pow(i, primes[i][1]);
      else
        ans *= pow(i, primes[i][0]);
    }
  }
  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-17
Problem: Problem Name/URL
*/
