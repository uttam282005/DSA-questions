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
#define gcd(a,b) __gcd(a,b)
#define pii pair<int, int>
#define all(x) (x.begin(), x.end())
#define umii unordered_map<int, int>
#define sorta(arr) sort(begin(arr), end(arr))
#define sortv(vec) sort(vec.begin(), vec.end())
#define itr(container) for(auto &it : container)
#define debug(x) cout << #x << '=' << x << endl
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve() {
  int n;
  cin >> n;
  vi v(n+1);
  vi pre(n+1);
  rep (i, 1, n+1) cin >> v[i];
  sortv(v);
  pre[0] = 1;
  pre[1] = v[1];
  rep (i, 2, n+1) pre[i] = pre[i-1] + v[i];
  rep (i, 1, n+1) {
    if (v[i] > pre[i-1]) {
      cout << "NO\n"; return;
    }
  }
  cout << "YES\n";
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
