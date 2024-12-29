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

void solve() {
  vi a = {4, 8, 15, 16, 23, 42};
  int a1, a2, a3, a4, a5, a6;

  cout << "? " << 1 << " " << 2 << endl;
  int res1;
  int b11, b12;
  cin >> res1;
  rep(i, 0, 6) {
    rep(j, 0, 6) {
      if (i == j)
        continue;
      if (a[i] * a[j] == res1) {
        b11 = a[i];
        b12 = a[j];
        break;
      }
    }
  }
  int commonElement;
  cout << "? " << 2 << " " << 3 << endl;
  int res2;
  cin >> res2;
  int b21, b22;
  rep(i, 0, 6) {
    rep(j, 0, 6) {
      if (i == j)
        continue;
      if (a[i] * a[j] == res2) {
        b21 = a[i];
        b22 = a[j];
        break;
      }
    }
  }
  if (b11 == b21 || b11 == b22)
    commonElement = b11;
  else if (b12 == b22 || b12 == b21)
    commonElement = b12;
  a2 = commonElement;

  a1 = res1 / a2;
  a3 = res2 / a2;

  cout << "? " << 4 << " " << 5 << endl;
  cin >> res1;
  rep(i, 0, 6) {
    rep(j, 0, 6) {
      if (i == j)
        continue;
      if (a[i] * a[j] == res1) {
        b11 = a[i];
        b12 = a[j];
        break;
      }
    }
  }
  cout << "? " << 5 << " " << 6 << endl;
  cin >> res2;
  rep(i, 0, 6) {
    rep(j, 0, 6) {
      if (i == j)
        continue;
      if (a[i] * a[j] == res2) {
        b21 = a[i];
        b22 = a[j];
        break;
      }
    }
  }
  if (b11 == b21 || b11 == b22)
    commonElement = b11;
  else if (b12 == b22 || b12 == b21)
    commonElement = b12;
  a5 = commonElement;

  a4 = res1 / a5;
  a6 = res2 / a5;
  cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " "
       << a6 << endl;
}

/*
Author: Uttam Raj
Date: 2024-12-21
Problem: Problem Name/URL
*/
