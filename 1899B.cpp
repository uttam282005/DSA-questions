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
#define repe(i, a, b) for (int i = a; i <= b; i++)

void solve() {
  int n;
  cin >> n;
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  vi pre(n);
  pre[0] = v[0];
  rep(i, 1, n) { pre[i] = pre[i - 1] + v[i]; }
  ll max_diff = 0;
  ll wt;
  repe(i, 1, n) {
    if (n % i != 0) continue;
    ll min_wt = LONG_LONG_MAX;
    ll max_wt = LONG_LONG_MIN;
    for (int j = 2 * i - 1; j < n; j = j + i) {
      wt = pre[j] - pre[j - i];
      max_wt = max(max_wt, wt);
      min_wt = min(min_wt, wt);
    }
    max_wt = max(max_wt, pre[i - 1]);
    min_wt = min(min_wt, pre[i - 1]);
    max_diff = max(max_diff, max_wt - min_wt);
  }
  cout << max_diff << endl;
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
