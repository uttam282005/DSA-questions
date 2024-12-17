#include <bits/stdc++.h>
using namespace std;

int largestCombination(vector<int> &candidates) {
  int ans = 1;
  int op = candidates[0];
  for (int i = 1; i < candidates.size(); i++) {
    if (!(op & candidates[i]))
      continue;
    op &= candidates[i];
    ans++;
  }
  return ans;
}
int main() {
  vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};
  largestCombination(candidates);
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-11-07
Problem: Problem Name/URL
*/
