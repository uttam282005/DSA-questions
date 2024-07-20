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
   int n, k, a, b; 
   cin >> n >> k >> a >> b;
   vector <pair<ll, ll>> v;
   ll xa, ya, xb, yb;
   rep (i, 1, n+1) {
	int x, y;
	cin >> x >> y;
   if (i <= k) v.pb(make_pair(x, y));
   if (i == a) {xa = x; ya = y;};
   if (i == b) {xb = x; yb = y;};
   }
   ll dis = abs(xa- xb) + abs(ya - yb);
   ll  minDisA = INT_MAX;
   ll  minDisB = INT_MAX;
   rep (i, 0, k) {
	minDisA = min(minDisA, abs(v[i].first - xa) + abs(v[i].second - ya));
	minDisB = min(minDisB, abs(v[i].first - xb) + abs(v[i].second - yb));
   }
   ll ans = min (dis, minDisA + minDisB);
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