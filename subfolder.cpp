#include <bits/stdc++.h>
using namespace std;
vector<string> removeSubfolders(vector<string> &folder) {
  sort(folder.begin(), folder.end());
  vector<string> ans;
  ans.push_back(folder[0]);
  for (int i = 1; i < folder.size(); i++) {
    string prefix;
    prefix = ans.back() + "/";
    if (folder[i].substr(0, prefix.size()) != prefix) {
      ans.push_back(folder[i]);
    }
  }
  return ans;
}

int main() {
  vector<string> folder = {"/a", "/a/b/c", "/a/b/d"};
  vector<string> newFolder = removeSubfolders(folder);
  for (int i = 0; i < newFolder.size(); i++) {
    cout << newFolder[i] << endl;
  }
  return 0;
}

/*
Author: Uttam Raj
Date: 2024-10-25
Problem: Problem Name/URL
*/
