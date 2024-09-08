// wrong solution because atleast one of the elements in the selected subarray
// has to be different
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define db double
#define ss second
#define si set<int>
#define mp make_pair
#define ll long long
#define pb push_back
#define um unordered_map
#define vi vector<ll int>
#define vs vector<string>
#define gcd(a, b) __gcd(a, b)
#define pii pair<int, int>
#define all(x) (x.begin(), x.end())
#define umii unordered_map<int, int>
#define sorta(arr) sort(begin(arr), end(arr))
#define sortv(vec) sort(vec.begin(), vec.end())
#define itr(container) for (auto &it : container)
#define debug(x) cout << #x << '=' << x << endl
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve() {
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  int l, r;
  rep(i, 0, n) {
    if (a[i] != b[i]) {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] != b[i]) {
      r = i;
      break;
    }
  }
  for (int i = l - 1; i >= 0; --i) {
    if (b[i] <= b[i + 1])
      l = i;
    else
      break;
  }
  for (int i = r + 1; i < n; i++) {
    if (b[i] >= b[i - 1])
      r = i;
    else
      break;
  }
  cout << l + 1 << " " << r + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
