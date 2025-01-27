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
void solveA();

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solveA();
  }
  return 0;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> c(n, vector<int>(m));
  rep(i, 0, n) {
    rep(j, 0, m) { cin >> c[i][j]; }
  }
  rep(i, 0, n) { sort(all(c[i])); }
  rep(i, 0, n) {
    rep(j, 1, m) {
      if (c[i][j] - c[i][j - 1] != n) {
        cout << -1 << endl;
        return;
      }
    }
  }
  vi ans(n);
  rep(i, 0, n) { ans[c[i][0]] = i + 1; }
  itr(ans) cout << it << " ";
  cout << endl;
}
void solveA() {
  int a1, a2, a4, a5;
  cin >> a1 >> a2 >> a4 >> a5;
  vi possible_a3 = {a1 + a2, a4 - a2, a5 - a4};

  int maxFibonacciness = 0;

  for (int a3 : possible_a3) {
    int count = 0;

    if (a3 == a1 + a2) {
      count++;
    }
    if (a4 == a2 + a3) {
      count++;
    }
    if (a5 == a3 + a4) {
      count++;
    }

    maxFibonacciness = max(maxFibonacciness, count);
  }
  cout << maxFibonacciness << endl;
}
/*
Author: Uttam Raj
Date: 2025-01-19
Problem: Problem Name/URL
*/
