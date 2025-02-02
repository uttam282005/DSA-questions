
#include <iostream>
#include <set>
using namespace std;

int main() {
  int x;
  cin >> x;
  while (x--) {
    int y;
    cin >> y;
    set<int> a, b;
    for (int i = 0, z; i < y; i++) {
      cin >> z;
      a.insert(z);
    }
    for (int i = 0, z; i < y; i++) {
      cin >> z;
      b.insert(z);
    }
    cout << ((a.size() * b.size() >= 3) ? "YES" : "NO") << endl;
  }
  return 0;
}
