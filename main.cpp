#include <bits/stdc++.h>
#include <climits>
#include <sched.h>
using namespace std;

vector<int> copy(int n, vector<int> arr) {
  vector<int> copyArray(n);
  for (int i = n - 1; i >= 0; i--)
    copyArray[i] = arr[i];
  return copyArray;
}
void insert(vector<int> arr, int n, int i, int value) {
  if (arr[i] == 0 && i < n)
    arr[i] = value;
}
void deleteElement(vector<int> arr, int n, int i) {
  if (arr[i] != 0 && arr[i] != INT_MIN)
    arr[i] = INT_MIN;
}
void modify(vector<int> arr, int n, int i, int value) {
  if (arr[i] != 0 && arr[i] != INT_MIN)
    arr[i] = value;
}
void display(vector<int> arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
}
