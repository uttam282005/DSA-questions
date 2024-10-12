#include <bits/stdc++.h>
using namespace std;

bool good(int threshold, vector<int> &nums, int mid) {
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += (nums[i] + mid - 1) / mid;
  }
  return sum <= threshold;
}
int smallestDivisor(vector<int> &nums, int threshold) {
  int low = 1, high = *max_element(nums.begin(), nums.end());
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (good(mid, nums)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}
int main() { return 0; }

/*
Author: Uttam Raj
Date: 2024-09-28
Problem: Problem Name/URL
*/
