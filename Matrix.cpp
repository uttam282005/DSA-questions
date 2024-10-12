// https://www.geeksforgeeks.org/problems/sums-of-i-th-row-and-i-th-column3054/1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int sumOfRowCol(int N, int M, vector<vector<int>> A) {
    vector<int> sumOfRows;
    for (int i = 0; i < A.size(); i++) {
      int sumOfRow = 0;
      for (int j = 0; j < A[i].size(); j++) {
        sumOfRow += A[i][j];
      }
      sumOfRows.push_back(sumOfRow);
    }
    vector<int> sumOfColumns;
    for (int i = 0; i < M; i++) {
      int sumOfColumn = 0;
      for (int j = 0; j < N; j++) {
        sumOfColumn += A[j][i];
      }
      sumOfColumns.push_back(sumOfColumn);
    }
    for (int i = 0; i < min(N, M); i++) {
      if (sumOfRows[i] != sumOfColumns[i]) {
        return 0;
      }
    }
    return 1;
  }
};

//{ Driver Code Starts
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> A[i][j];
    Solution ob;
    cout << ob.sumOfRowCol(N, M, A) << "\n";
  }
}
// } Driver Code Ends
