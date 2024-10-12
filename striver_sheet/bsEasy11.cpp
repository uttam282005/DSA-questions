#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int mid;
  while (high - low > 1) {
    mid = (low + high) / 2;
    if (arr[mid - 1] > arr[mid] && arr[mid] < arr[mid + 1]) {
      return mid;
    }
    if (arr[low] <= arr[mid]) {
      low = mid + 1;
    } else
      high = mid - 1;
  }
  if (arr[low] <= arr[high])
    return 0;
  else
    return high;
}

int main() {
  int n;
  int k = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << findKRotation(v);
}
