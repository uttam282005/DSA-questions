#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ff first
#define db double
#define ss second
#define si set<int>
#define mp make_pair
#define ll long long
#define pb push_back
#define um unordered_map
#define vi vector<int>
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
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  ll sum = max(v[0], 0);
  ll max_sum = LONG_LONG_MIN;
  rep(i, 1, n) {
    if (v[i] % 2 != v[i - 1] % 2) {
      sum += v[i];
      max_sum = max(max_sum, sum);
      if (sum < 0)
        sum = 0;
    } else {
      sum = 0;
      sum += v[i];
      max_sum = max(max_sum, sum);
      if (sum < 0)
        sum = 0;
    }
  }
  cout << max_sum << endl;
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
