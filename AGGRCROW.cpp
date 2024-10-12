#include <bits/stdc++.h>
using namespace std;

bool good(int mid, vector<int> v, int n, int k) {
  int cowsPlaced = 1;
  int last = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] - last >= mid) {
      cowsPlaced++;
      last = v[i];
    }
  }
  return cowsPlaced >= k;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int low = 1;
    int high = v[n - 1] - v[0];
    int mid;
    while (high - low > 1) {
      mid = (low + high) / 2;
      if (good(mid, v, n, k)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    if (good(high, v, n, k))
      cout << high;
    else
      cout << low << endl;
  }
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-10-01
Problem: Problem Name/URL
*/
