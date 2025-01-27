
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t; // Number of test cases
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> evens, odds;

    // Read the array and separate into evens and odds
    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      if (num % 2 == 0) {
        evens.push_back(num);
      } else {
        odds.push_back(num);
      }
    }

    // Combine evens first, then odds
    vector<int> sorted_array = evens;
    sorted_array.insert(sorted_array.end(), odds.begin(), odds.end());

    long long s = 0;
    int points = 0;

    // Simulate the process
    for (int x : sorted_array) {
      s += x;
      if (s % 2 == 0) {
        points++;
        // Divide s by 2 until it becomes odd
        while (s % 2 == 0) {
          s /= 2;
        }
      }
    }

    cout << points << endl; // Output the maximum points for this test case
  }

  return 0;
}
