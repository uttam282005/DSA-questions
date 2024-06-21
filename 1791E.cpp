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
#define vi vector< int>
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
   vi v(n);
   int cnt = 0;
   ll sum = 0;
   int cntZero = 0;
   int minAbs = INT_MAX;
   rep (i, 0, n){
    cin >> v[i];
    sum += abs(v[i]);
    minAbs = min(minAbs, abs(v[i]));
    if (v[i] < 0) cnt++;
    if (v[i] == 0) cntZero++;
   }
   if (cnt & 1) {
    if ((cnt + cntZero) & 1){
        cout << sum - 2*minAbs << endl;
    } else {
        cout << sum << endl;
    }
   } else {
    cout << sum << endl;
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