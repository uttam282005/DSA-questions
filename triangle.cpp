#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  vector<vector<int>> dp(k + 1, vector<int>(n, 0));

  dp[0][0] = (arr[0] == 0) ? 2 : 1;
  for (int j = 1; j < n; j++) {
    if (arr[j] == 0)
      dp[0][j] += dp[0][j - 1] + 2;
    else
      dp[0][j] += dp[0][j - 1];
  }

  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0)
        dp[i][j] += dp[i][j - 1];

      if (i >= arr[j] && j > 0) {
        dp[i][j] += dp[i - arr[j]][j - 1];
      } else if (i == arr[j] && j == 0) {
        dp[i][j] += 1;
      }
    }
  }

  return dp[k][n - 1];
}

int main() {
  vector<int> arr = {0, 0, 1};
  cout << findWays(arr, 1);
  return 0;
}

/*
Author: Uttam Raj
Date: 2025-04-09
Problem: Problem Name/URL
*/
