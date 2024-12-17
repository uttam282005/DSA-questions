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
const int MOD = 998244353;
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
long long factorial(int x) {
  if (x == 0)
    return 1;
  return (factorial(x - 1) % MOD * x % MOD) % MOD;
}

void solve() {
  // Solution
  // Start coding here
  string s;
  cin >> s;
  s += '4';
  long long cnt = 0;
  long long numberOfOps = 0;
  long long seq = 1;
  rep(i, 0, s.size() - 1) {
    if (s[i] != s[i + 1]) {
      numberOfOps += cnt;
      seq = ((seq % MOD) * (cnt + 1) % MOD) % MOD;
      cnt = 0;
    } else
      cnt++;
  }
  cout << numberOfOps << " " << (seq % MOD * factorial(numberOfOps) % MOD) % MOD
       << endl;
}

/*
Author: Uttam Raj
Date: 2024-11-12
Problem: Problem Name/URL
*/
