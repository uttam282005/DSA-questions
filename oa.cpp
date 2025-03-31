#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  char inf;
  cin >> s >> inf;
  vector<int> diff;
  int n = s.size();
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == inf and i != 0) {
      diff.push_back(i - prev);
      prev = i;
    }
  }
  sort(diff.begin(), diff.end());
  int time = 0;
  for (auto it : diff) {
    it -= time;
    if (it > 0)
      time += it;
  }
  cout << time;
}
