#include <bits/stdc++.h>
using namespace std;

bool good(vector<int> weights, int days, int mid) {
  int daysRequired = 0;
  int load = 0;
  for (int i = 0; i < weights.size(); i++) {
    if (load + weights[i] > mid) {
      daysRequired++;
      load = 0;
    }
    load += weights[i];
  }
  return daysRequired <= days;
}

int shipWithinDays(vector<int> &weights, int days) {
  int low = 0;
  int high = 1e7;
  int mid;
  while (high - low > 1) {
    mid = (low + high) / 2;
    if (good(weights, days, mid))
      high = mid;
    else
      low = mid + 1;
  }
  if (good(weights, days, low))
    return low;
  return high;
}

int main() {
  vector<int> v;
  v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  good(v, 5, 15);
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-09-28
Problem: Problem Name/URL

