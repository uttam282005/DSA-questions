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
db leftIndex = 0;
db rightIndex = 0;
bool checker(db x, db sum, vector<db> v, int d) {
  int l = 0;
  int r = v.size() - 1;
  vector<db> p(v.size());
  vector<pair<db, int>> min_p(v.size());
  p[0] = v[0];
  min_p[0].first = p[0];
  min_p[0].second = 0;
  rep(i, 1, v.size()) {
    p[i] = v[i] + p[i - 1];
    if (p[i] < min_p[i - 1].first) {
      min_p[i].first = p[i];
      min_p[i].second = i;
    } else
      min_p[i] = min_p[i - 1];
  }
  rep(i, d - 1, v.size()) {
    if (i - d >= 0 && min_p[i - d].first <= p[i]) {
      leftIndex = min_p[i - d].second + 1;
      rightIndex = i;
      return true;
    } else if (p[i] >= 0) {
      leftIndex = 0;
      rightIndex = i;
      return true;
    }
  }
  return false;
}

void solve() {
  int n;
  int d;
  cin >> n >> d;
  vi v(n);
  rep(i, 0, n) { cin >> v[i]; }
  db low = 0;
  db high = 1e6;
  db mid;
  db mean;
  for (int i = 0; i < 110; i++) {
    mid = (low + high) / 2;
    vector<db> t(n);
    db sum = 0;
    rep(i, 0, n) {
      t[i] = v[i] - mid;
      sum += t[i];
    }
    if (checker(mid, sum, t, d)) {
      mean = mid;
      low = mid;
    } else
      high = mid;
  }
  cout << leftIndex + 1 << " " << rightIndex + 1;
}

/*
Author: Uttam Raj
Date: 2024-12-18
Problem: Problem Name/URL
*/
