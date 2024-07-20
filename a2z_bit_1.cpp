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

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}    

int findXOR(int l, int r) {
        int a, b;
        if (l-1 % 4 == 0) a = l-1;
        else if (l-1 % 4 == 1) a = 1;
        else if (l-1 % 4 == 2) a = l;
        else a = 0;
        
        if (r % 4 == 0) b = r;
        else if (r % 4 == 1) b = 1;
        else if (r % 4 == 2) b = r + 1;
        else b = 0;
        
        int ans = b ^ a;
        debug(a);
        debug(b);
        return ans;
    }
void solve() {
    int ans = 0;
        // cout << i << " " ; printBinary(i);
        cout << findXOR(10, 10);
  
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