
#include <bits/stdc++.h>
using namespace std;

// Constants
const int N = 100001;
int spf[N];      // Smallest Prime Factor
int occupied[N]; // Tracks if a prime factor is occupied
int isActive[N]; // Tracks if a number is active
int isPrime[N];  // Marks primes

void solve() {
  int n, m;
  cin >> n >> m;

  // Initialize arrays
  fill(isPrime, isPrime + N, 1);
  fill(spf, spf + N, 0);
  fill(occupied, occupied + N, 0);
  fill(isActive, isActive + N, 0);

  // Sieve of Eratosthenes to compute smallest prime factors
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      spf[i] = i; // Smallest prime factor of a prime is itself
      for (long long j = (long long)i * i; j < N; j += i) {
        isPrime[j] = 0;
        if (spf[j] == 0)
          spf[j] = i;
      }
    }
  }

  // Processing queries
  for (int i = 0; i < m; i++) {
    char type;
    int c;
    cin >> type >> c;

    if (c <= 0 || c >= N) { // Guard against invalid input
      cout << "Invalid input: " << c << endl;
      continue;
    }

    if (type == '+') {
      if (isActive[c]) {
        cout << "Already on" << endl;
        continue;
      }

      bool isConflict = false;
      int original_c = c;
      int conflict = -1;

      while (c != 1) {
        int pf = spf[c];
        if (occupied[pf]) {
          isConflict = true;
          conflict = occupied[pf];
          break;
        }
        c /= pf;
      }

      if (isConflict) {
        cout << "Conflict with " << conflict << endl;
      } else {
        cout << "Success" << endl;
        isActive[original_c] = 1;
        c = original_c;
        while (c != 1) {
          int pf = spf[c];
          occupied[pf] = original_c;
          c /= pf;
        }
      }
    } else if (type == '-') {
      if (!isActive[c]) {
        cout << "Already off" << endl;
        continue;
      }

      isActive[c] = 0;
      int original_c = c;

      while (c != 1) {
        int pf = spf[c];
        occupied[pf] = 0;
        c /= pf;
      }

      cout << "Success" << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}
