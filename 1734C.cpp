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
  string s;
  cin >> s;
  ll cost = 0;
  rep(i, 0, n) {
    if (s[i] == '0' || s[i] == '2') {
      for (int j = i + 1; j < n + 1; j += i + 1) {
        if (s[j - 1] == '0') {
          cost += (i + 1);
          s[j - 1] = '2';
        } else if (s[j - 1] == '1')
          break;
      }
    }
  }
  cout << cost << endl;
}

/*
Author: Uttam Raj
Date: 2024-09-27
Problem: Problem Name/URL
*/
