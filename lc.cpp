#include <bits/stdc++.h>
using namespace std;

int studentCount(vector<int> &arr, int n, int m, int mid) {
  long long pages = 0;
  int students = 1;
  for (int i = 0; i < n; i++) {
    if (pages + arr[i] <= mid)
      pages += arr[i];
    else {
      pages = arr[i];
      students++;
    }
  }
  return students;
}

int findPages(vector<int> &arr, int n, int m) {
  // Write your code here.
  if (m > n)
    return -1;
  int low = 1;
  long long high = accumulate(arr.begin(), arr.end(), 0);
  int mid;
  while (high - low > 1) {
    mid = (low + high) / 2;
    if (studentCount(arr, n, m, mid) <= m)
      high = mid;
    else
      low = mid + 1;
  }
  if (studentCount(arr, n, m, low) <= m)
    return low;
  if (studentCount(arr, n, m, high) <= m)
    return high;
  return -1;
}

int main() {
  vector<int> arr = {2, 8, 8, 4, 5};
  cout << findPages(arr, 5, 2);
  return 0;
}
/*
Author: Uttam Raj
Date: 2024-10-02
Problem: Problem Name/URL
*/
