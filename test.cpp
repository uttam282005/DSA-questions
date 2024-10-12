#include <bits/stdc++.h>
using namespace std;

int minSubarray(vector<int> &nums, int p) {
  unordered_map<int, int> hsh;
  int n = nums.size();
  vector<long long int> prefix_sum(n);
  prefix_sum[0] = nums[0];
  for (int i = 1; i < n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + nums[i];
  }
  if (prefix_sum[n - 1] % p == 0)
    return 0;
  int minLength = INT_MAX;
  int target = prefix_sum[n - 1] - (prefix_sum[n - 1] % p);
  bool enter = false;
  while (target) {
    long long rem = prefix_sum[n - 1] - target;

    for (int i = 0; i < n; i++) {
      if (prefix_sum[i] == rem) {
        minLength = min(minLength, n - (i + 1));
        enter = true;
      }
      if (hsh.find(prefix_sum[i] - rem) != hsh.end()) {
        minLength = min(minLength, i - hsh[prefix_sum[i] - rem]);
        enter = true;
      }
      hsh[prefix_sum[i]] = i;
    }

    target -= p;
  }
  if (!enter)
    return -1;
  return minLength;
}
int main() {
  vector<int> arr = {8,  32, 31, 18, 34, 20, 21, 13, 1,
                     27, 23, 22, 11, 15, 30, 4,  2};
  cout << minSubarray(arr, 148);
  return 0;
}
