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
  int n, k;
  cin >> n >> k;
  vi a(n);
  vi b(n);
  vi pre(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  pre[0] = a[0];
  rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
  int repeat = INT_MIN;
  int current_score = 0;
  int max_score = INT_MIN;
  rep(i, 0, min(n, k)) {
    current_score = 0;
    current_score += pre[i];
    repeat = max(repeat, b[i]);
    current_score += repeat * (k - (i + 1));
    max_score = max(max_score, current_score);
  }
  cout << max_score << endl;
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
