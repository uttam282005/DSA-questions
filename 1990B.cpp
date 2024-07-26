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
#define debug(x) cout << #x << '=' << x << endl
#define itr(container) for (auto &it : container)
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  --x;
  --y;
  vi v(n, 1);
  for (int i = y - 1; i >= 0; i--) {
    v[i] = -1 * v[i + 1];
  }

  rep(i, x + 1, n) { v[i] = -1 * v[i - 1]; }
  rep(i, 0, n) cout << v[i] << " ";
  cout << endl;
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
