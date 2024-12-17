//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  void findPaths(int row, int col, vector<vector<int>> &mat,
                 vector<vector<bool>> &visited, vector<string> &ans,
                 string &directions) {
    if (row < 0 || row > mat.size() || col < 0 || col > mat[0].size())
      return;
    if (visited[row][col] || mat[row][col] == 0)
      return;
    if (row == mat.size() && col == mat[0].size()) {
      ans.push_back(directions);
    }

    directions += 'D';
    visited[row][col] = true;
    findPaths(row + 1, col, mat, visited, ans, directions);
    directions.pop_back();

    directions += 'L';
    findPaths(row, col - 1, mat, visited, ans, directions);
    directions.pop_back();

    directions += 'R';
    findPaths(row, col + 1, mat, visited, ans, directions);
    directions.pop_back();

    directions += 'U';
    findPaths(row - 1, col, mat, visited, ans, directions);
    directions.pop_back();

    visited[row][col] = false;
  }
  vector<string> findPath(vector<vector<int>> &mat) {
    // Your code goes here
    vector<string> ans;
    string directions = "";
    vector<vector<bool>> visited(mat.size(),
                                 vector<bool>(mat[0].size(), false));
    findPaths(0, 0, mat, visited, ans, directions);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
      }
    }
    Solution obj;
    vector<string> result = obj.findPath(m);
    sort(result.begin(), result.end());
    if (result.size() == 0)
      cout << -1;
    else
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    cout << "~"
         << "\n";
  }
  return 0;
}
// } Driver Code Ends
