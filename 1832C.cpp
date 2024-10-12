#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  vi a(n);
  rep(i, 0, n) cin >> a[i];
  int cnt = 1;
  int state = 0;
  rep(i, 1, n) {
    if (a[i - 1] < a[i] and state != 1) {
      state = 1;
      cnt++;
    } else if (a[i - 1] > a[i] and state != -1) {
      state = -1;
      cnt++;
    }
  }
  cout << cnt << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-04
Problem: Problem Name/URL
*/
