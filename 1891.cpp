#include <bits/stdc++.h>
using namespace std;

#define ff first
#define db double
#define ss second
#define si set<ll int>
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi x(q);
    umii hsh; 
    rep (i, 0, n) cin >> a[i];
    rep (i, 0, q) cin >> x[i];
    rep (i, 0, q) {
        if (hsh[x[i]] > 0) continue;
        hsh[x[i]]++;
        rep (j, 0, n) {
            if (a[j] % (1 << x[i]) == 0) a[j] += (1 << (x[i] - 1));
        }
    }
    rep (i, 0, n) cout << a[i] << " ";
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