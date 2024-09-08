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
  int n, k;
  cin >> n >> k;
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  vi pre(n);
  sortv(v);
  pre[0] = v[0];
  rep(i, 1, n) pre[i] = v[i] + pre[i - 1];
  ll ans = INT_MIN;
  rep(i, 1, k + 1) ans = max(ans, pre[n - (k - i) - 1] - pre[2 * i - 1]);
  ans = max(ans, pre[n - k - 1]);
  cout << ans << endl;
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
