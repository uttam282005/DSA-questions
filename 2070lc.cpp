#include <bits/stdc++.h>
using namespace std;

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
  sort(queries.begin(), queries.end());
  sort(items.begin(), items.end(),
       [](const vector<int> &i, const vector<int> &j) { return i[0] < j[0]; });
}
int main() { return 0; }

/*
Author: Uttam Raj
Date: 2024-11-12
Problem: Problem Name/URL
*/
