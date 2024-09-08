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
  int n;
  cin >> n;
  vi v(n);
  rep(i, 0, n) cin >> v[i];
  ll time = 0;
  ll p = 1;
  vi iv(n);
  umii hsh;
  iota(iv.begin(), iv.end(), 0);
  stable_sort(iv.begin(), iv.end(), [&](int i, int j) { return v[i] <= v[j]; });
  for (int i = n - 1; i >= 1; i--) {
    hsh[iv[i]] = p;
    hsh[iv[i - 1]] = -p;
    time += v[iv[i]] * p * 2 + v[iv[i - 1]] * 2 * p;
    p++;
    i--;
  }
  if (n % 2 != 0) {
    time += v[iv[0]] * p * 2;
    hsh[iv[0]] = p;
  }
  cout << time << endl;
  cout << 0 << " ";
  rep(i, 0, n) { cout << hsh[i] << " "; }
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
