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

void printBinary(int n){
  for (int i = 7; i >= 0; --i) {
    cout << ((n >> i) & 1);
  }
    cout << endl;
}
void solve() {
  int a = 31;
  int i = 1;
  // Check whether a bit is set or not (zero based indexing)
  if (a & (1 << i)) cout << "SET\n";
  else cout << "UNSET\n";
  // Set bit
  cout << (a | (1 << 2)) << endl;
  // Unset bit
  cout << (a & ~(1 << 2)) << endl;
  // Toggle
  cout << (a ^ (1 << 2)) << endl;
  // Counting set bits
  int cnt = 0;
  for (int i = 8; i >= 0; --i) {
    if (a & (1 << i)) cnt++;
  }
  cout << cnt << endl;
  printBinary(3);
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
