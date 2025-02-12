#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> findOriginalArray(vector<int> &changed) {
  map<int, int> track;
  vector<int> ans;

  for (int i = 0; i < changed.size(); i++) {
    track[changed[i]]++;
  }
  for (int i = 0; i < changed.size(); i++) {
    if (track[changed[i]]) {
      if (changed[i] % 2 != 0) {
        if (track[changed[i] * 2]) {
          ans.push_back(changed[i]);
          track[changed[i]]--;
          track[changed[i] * 2]--;
          cout << changed[i] * 2 << endl;
          cout << "tr=" << track[2];
        } else
          return {};
      } else if (track[changed[i] / 2] && !track[changed[i] * 2]) {
        cout << "i=" << i << endl;
        ans.push_back(changed[i] / 2);
        track[changed[i] / 2]--;
        track[changed[i]]--;
      }
    }
    cout << endl;
  }

  for (auto it : track) {
    if (it.second != 0)
      return {};
  }
  return ans;
}
int main() {
  vector<int> changed = {1, 2, 3, 2, 4, 6, 2, 4, 6, 4, 8, 12};
  findOriginalArray(changed);

  return 0;
}

/*
Author: Uttam Raj
Date: 2025-02-10
Problem: Problem Name/URL
*/
