#include <bits/stdc++.h>
using namespace std;

// Defines
#define db double
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).length()
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
  string num;
  cin >> num;
  int n = num.length();
  string even = "";
  string odd = "";
  rep(i, 0, n) {
    if ((num[i] - '0') % 2 == 0)
      even += num[i];
    else
      odd += num[i];
  }

  int p1 = 0;
  int p2 = 0;
  string ans = "";

  while (p1 < even.length() && p2 < odd.length()) {
    if (even[p1] - '0' < odd[p2] - '0') {
      ans += even[p1];
      p1++;
    } else {
      ans += odd[p2];
      p2++;
    }
  }
  while (p1 < even.length()) {
    ans += even[p1];
    p1++;
  }

  while (p2 < odd.length()) {
    ans += odd[p2];
    p2++;
  }
  cout << ans << endl;
}

/*
Author: Uttam Raj
Date: 2025-01-09
Problem: Problem Name/URL
*/
