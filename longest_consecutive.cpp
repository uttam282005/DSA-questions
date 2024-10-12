#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int n;
  int N = 1e7;
  cin >> n;
  vector<int> temp(n);
  vector<bool> occur(N + 1, false);
  for (int i = 0; i < n; i++) {
    cin >> temp[i];
    occur[temp[i]] = true;
  }
  int count = 0;
  int max_count = 0;
  for (int i = 0; i < N; ++i) {
    if (occur[i] && occur[i + 1])
      count++;
    else
      max_count = max(max_count, count);
  }
  cout << max_count + 1 << endl;
}
