



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
#define find(v, a) find(v.begin(), v.end(), a)
#define all(x) (x.begin(), x.end())
#define umii unordered_map<int, int>
#define sorta(arr) sort(begin(arr), end(arr))
#define sortv(vec) sort(vec.begin(), vec.end())
#define itr(container) for (auto &it : container)
#define debug(x) cout << #x << '=' << x << endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cnt(v, a) count(v.begin(), v.end(), a)
#define rev(v) reverse(v.begin(), v.end())
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())
#define repe(i, a, b) for (int i = a; i <= b; i++)

auto print_con = [](auto v) { itr(v) cout << it << " "; };
auto print_arr = [](auto arr[], int n) { rep(i, 0, n) cout << arr[i] << " "; };

// don't forget long long

void solve() {
  ll a, b;
  cin >> a >> b;
  ll cnt = 0;
  if (b >= a) {
    while (a <= b) {
      if (a == b) {
        cout << cnt << endl;
        return;
      }
      if ((a << 3) <= b) {
        cnt++;
        a = a << 3;
      } else if ((a << 2) <= b) {
        cnt++;
        a = a << 2;
      } else {
        a = a << 1;
        cnt++;
      }
    }
    cout << -1 << endl;
    return;
  }
  if (b < a) {
    while (a >= b) {
      if (a == b) {
        cout << cnt << endl;
        return;
      }
      if ((a >> 3) >= b && a % 8 == 0) {
        cnt++;
        a = a >> 3;
      } else if ((a >> 2) >= b && a % 4 == 0) {
        cnt++;
        a = a >> 2;
      } else if (a % 2 == 0) {
        cnt++;
        a = a >> 1;
      } else {
        cout << -1 << endl;
        return;
      }
    }
    cout << -1 << endl;
    return;
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
