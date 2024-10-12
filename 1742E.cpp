#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Defines
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(...) _f(#__VA_ARGS__, __VA_ARGS__)
#define itr(v)                                                                 \
  for (auto it : v)                                                            \
  cout << it << endl

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
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  vi b(q);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, q) cin >> b[i];
  vi c = b;
  a[n] = INT_MAX;
  sort(b.begin(), b.end());
  unordered_map<int, ll> hsh;
  int last = 0;
  vll prefix(n);
  prefix[0] = a[0];
  rep(i, 1, n) prefix[i] = prefix[i - 1] + a[i];
  rep(i, 0, q) {
    rep(j, last, n + 1) {
      if (b[i] < a[j]) {
        last = j;
        if (j == 0)
          hsh[b[i]] = 0;
        else
          hsh[b[i]] = prefix[j - 1];
        break;
      }
    }
  }
  rep(i, 0, q) cout << hsh[c[i]] << " ";
  cout << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-04
Problem: Problem Name/URL
*/
