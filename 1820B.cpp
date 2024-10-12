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

// Sort functions
template <typename T> void sort_asc(vector<T> &v) { sort(v.begin(), v.end()); }

template <typename T> void sort_desc(vector<T> &v) {
  sort(v.begin(), v.end(), greater<T>());
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
  // Solution
  // Start coding here
  string s;
  cin >> s;
  int cnt = 0;
  int maxCnt = INT_MIN;
  s += s;
  for (auto it : s) {
    if (it == '1')
      cnt++;
    else {
      maxCnt = max(cnt, maxCnt);
      cnt = 0;
    }
  }
  maxCnt = max(cnt, maxCnt);
  int n = s.size() / 2;
  if (maxCnt > n) {
    cout << 1ll * n * n << endl;
    return;
  }
  if ((maxCnt + 1) % 2 == 0) {
    cout << (1ll * (maxCnt + 1) / 2) * ((maxCnt + 1) / 2) << endl;
    return;
  }
  cout << (1ll * (maxCnt + 1) / 2) * (((maxCnt + 1) / 2) + 1) << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-05
Problem: Problem Name/URL
*/
