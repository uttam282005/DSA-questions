#include <bits/stdc++.h>
using namespace std;

// Function prototypes
bool enough(long long k, vector<int> piles, int n, int h) {
  int hours = 0;
  for (int i = 0; i < n; i++) {
    hours += (int)ceil((double)piles[i] / k);
  }
  return hours <= h;
}
int minEatingSpeed(vector<int> &piles, int h) {
  int n = piles.size();
  int low = 1;
  long long int high = 1e15;
  long long mid;
  while (high - low > 1) {
    mid = (high - low) / 2 + low;
    if (enough(mid, piles, n, h))
      high = mid;
    else
      low = mid + 1;
  }
  if (enough(low, piles, n, h))
    return low;
  else
    return high;
}
// Main function
int main() {
  int n;
  cin >> n;
  vector<int> piles(n);
  for (int i = 0; i < n; i++)
    cin >> piles[i];
  int h;
  cin >> h;
  cout << minEatingSpeed(piles, h);
}

/*
Author: Uttam Raj
Date: 2024-09-28
Problem: Problem Name/URL
*/
