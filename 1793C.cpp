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
#define debug(x) cout << #x << " = " << x << endl
#define itr(v) for (auto it : v)

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
  int l = 0, r = n - 1;
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  int min_element = 1;
  int max_element = n;
  while (l < r) {
    if (v[l] == min_element) {
      l++;
      min_element++;
    } else if (v[l] == max_element) {
      l++;
      max_element--;
    } else if (v[r] == max_element) {
      r--;
      max_element--;
    } else if (v[r] == min_element) {
      r--;
      min_element++;
    } else {
      cout << l + 1 << " " << r + 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}

/*
Author: Uttam Raj
Date: 2024-09-28
Problem: Problem Name/URL
*/
