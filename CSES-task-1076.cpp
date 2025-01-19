
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Policy-based data structure
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Defines
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;

// Constants
const int MOD = 1e9 + 7;

// Function prototypes
void solve();

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi nums(n);
  rep(i, 0, n) cin >> nums[i];

  ordered_set<pair<int, int>> temp;
  rep(i, 0, k) { temp.insert({nums[i], i}); }
  for (int i = k; i <= n; i++) {
    int median = temp.find_by_order((k - 1) / 2)->first;
    cout << median << " ";

    if (i < n) {
      temp.insert({nums[i], i});
      temp.erase(temp.lower_bound({nums[i - k], 0}));
    }
  }
}
