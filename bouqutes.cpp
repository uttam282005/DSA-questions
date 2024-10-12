#include <bits/stdc++.h>
using namespace std;

bool good(int days, vector<int> bloomDay, int m, int k) {
  int numberOfBouquets = 0;
  int adjacentFlowers = 0;
  for (int i = 0; i < bloomDay.size(); i++) {
    if (bloomDay[i] <= days) {
      adjacentFlowers++;
    } else {
      adjacentFlowers = 0;
    }
    if (adjacentFlowers == k) {
      numberOfBouquets++;
      adjacentFlowers = 0;
    }
  }
  return numberOfBouquets >= m;
}
int minDays(vector<int> &bloomDay, int m, int k) {
  int low = 1;
  int high = *max_element(bloomDay.begin(), bloomDay.end());
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (good(mid, bloomDay, m, k)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  if (good(low, bloomDay, m, k)) {
    return low;
  }
  if (good(high, bloomDay, m, k)) {
    return high;
  }
  return -1;
}
int main() {
  vector<int> bloomDay = {1, 10, 3, 10, 2};
  int m = 3, k = 2;
  cout << minDays(bloomDay, m, k);
}

/*
Author: Uttam Raj
Date: 2024-09-28
Problem: Problem Name/URL
*/
