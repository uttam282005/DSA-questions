#include <bits/stdc++.h>
using namespace std;

struct operation {
  int l;
  int r;
};

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
  int n;
  int x;
  int m;
  cin >> n >> x >> m;
  x--;
  vector<operation> v(m);
  rep(i, 0, m) {
    cin >> v[i].l;
    cin >> v[i].r;
    v[i].l--;
    v[i].r--;
  }
  operation valid;
  int start = -1;
  rep(i, 0, m) {
    if (x >= v[i].l && x <= v[i].r) {
      valid = v[i];
      start = i;
      break;
    }
  }
  if (start == -1) {
    cout << 1 << endl;
    return;
  }
  int lb = valid.l;
  int ub = valid.r;
  rep(i, start + 1, m) {
    int ll = max(v[i].l, lb);
    int ul = min(v[i].r, ub);
    if (ll <= ul) {
      lb = min(lb, v[i].l);
      ub = max(ub, v[i].r);
    }
  }
  cout << ub - lb + 1 << endl;
}

/*
Author: Uttam Raj
Date: 2024-12-14
Problem: Problem Name/URL
*/
