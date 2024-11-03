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
#define itr(v) for (auto it : v)

template <typename Arg1> void _f(const char *name, Arg1 &&arg1) {
  cout << name << ":" << arg1 << endl;
}

template <typename Arg1, typename... Args>
void _f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << arg1 << "|";
  _f(comma + 1, args...);
}

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
  int n, m;
  cin >> n >> m;
  vi v;
  rep(i, 0, m) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  v.push_back(v[0]);
  vi d;
  rep(i, 0, m) { d.push_back((v[i + 1] - v[i] - 1 + n) % n); };
  sort(d.begin(), d.end());
  int l = m - 1;
  int saved = 0;
  int days = 0;
  while (d[l] > 1 && l >= 0) {
    saved += (d[l] - 1);
    days += 2;
    l--;
    if (l < 0) break;
    d[l] = max(d[l] - 2 * days, 0);
  }
  if (d[l] == 1)
    saved++;
  cout << n - saved << endl;
}

/*
Author: Uttam Raj
Date: 2024-10-05
Problem: Problem Name/URL
*/
