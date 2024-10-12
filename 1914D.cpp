#include <bits/stdc++.h>
#include <climits>
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
#define debug(x) cout << #x << " = " << x << endl

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
  int n;
  cin >> n;
  vll a(n);
  rep(i, 0, n) { cin >> a[i]; }
  vll b(n);
  rep(i, 0, n) { cin >> b[i]; }
  vll c(n);
  rep(i, 0, n) { cin >> c[i]; }
  vi i_a(n);
  vi i_b(n);
  vi i_c(n);
  iota(i_a.begin(), i_a.end(), 0);
  iota(i_b.begin(), i_b.end(), 0);
  iota(i_c.begin(), i_c.end(), 0);

  sort(i_a.begin(), i_a.end(), [&](int i, int j) { return a[i] > a[j]; });
  sort(i_b.begin(), i_b.end(), [&](int i, int j) { return b[i] > b[j]; });
  sort(i_c.begin(), i_c.end(), [&](int i, int j) { return c[i] > c[j]; });

  ll max_sum = INT_MIN;
  rep(i, 0, 3) {
    rep(j, 0, 3) {
      rep(k, 0, 3) {
        if (i_a[i] == i_b[j] || i_a[i] == i_c[k] || i_b[j] == i_c[k])
          continue;
        max_sum = max(max_sum, a[i_a[i]] + b[i_b[j]] + c[i_c[k]]);
      }
    }
  }
  cout << max_sum << endl;
}
/*
Author: Uttam Raj
Date: 2024-09-23
Problem: Three activites/https://codeforces.com/problemset/problem/1914/D
*/
