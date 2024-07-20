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

ll int good(ll w, vi v, ll n, ll c) {
    ll sums = 0;
    rep (i, 0, n) {
        sums += (v[i] + 2*w) * (v[i] + 2*w);
        if (sums > c) break;
        } 
    return sums;
}

void solve() {
    ll n, c;
    cin >> n >> c;
    vi v(n);
    rep (i, 0, n) cin >> v[i];
    ll l = 1;
    ll r = 1e9 + 10;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (good(mid, v, n, c) == c) {
            cout << mid << endl;
            return;
        }
        else if (good(mid, v, n, c) < c) l = mid + 1;
        else r = mid - 1;
    }
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