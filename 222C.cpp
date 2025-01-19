#include <bits/stdc++.h>
using namespace std;

// Defines
#define db double
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define itr(container) for (auto &it : container)
#define ss second
#define gcd(a, b) __gcd(a, b)
#define vs vector<string>
#define um unordered_map
#define pb push_back
#define umii unordered_map<int, int>
#define sortv(arr) sort(arr.begin(), arr.end())

// Typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

// Debug Function
#define debug(...) _f(#__VA_ARGS__, __VA_ARGS__)

// Sorting Functions
template <typename T> void sort_vec(vector<T> &v) { sort(v.begin(), v.end()); }

template <typename T> void sort_desc(vector<T> &v) {
  sort(v.begin(), v.end(), greater<T>());
}

// Debug function definitions
template <typename Arg1> void _f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void _f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ":" << arg1 << "|";
  _f(comma + 1, args...);
}

// Function prototypes
void solve();

// Main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}
const int N = 1e7 + 1;
int spf[N];
vector<bool> isPrime(N, 1);

void sieve() {
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      spf[i] = i;
      for (ll j = i * 1ll * i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  vi n(a);
  vi d(b);
  rep(i, 0, a) cin >> n[i];
  rep(i, 0, a) cin >> d[i];
  sieve();
  vi primes(N);
  set<int> unique_primes;
  rep(i, 0, a) {
    while (n[i] != 1) {
      int pf = spf[n[i]];
      while (n[i] % pf == 0) {
        primes[pf]++;
        n[i] /= pf;
      }
      unique_primes.insert(pf);
    }
  }
  rep(i, 0, b) {
    while (d[i] != 1) {
      int pf = spf[d[i]];
      while (d[i] % pf == 0) {
        primes[pf]--;
        d[i] /= pf;
      }
      unique_primes.insert(pf);
    }
  }
  int number_of_num = 0;
  int number_of_den = 0;
  itr(unique_primes) {
    if (primes[it] > 0)
      number_of_num++;
    else if (primes[it] < 0)
      number_of_den++;
  }
  if (number_of_den == 0) {
    number_of_den += 1;
    unique_primes.insert(1);
    primes[1] = -1;
  }

  if (number_of_num == 0) {
    number_of_num += 1;
    unique_primes.insert(1);
    primes[1] = 1;
  }
  cout << number_of_num << " " << number_of_den << endl;
  itr(unique_primes) {
    if (primes[it] > 0)
      cout << pow(it, primes[it]) << " ";
  }

  cout << endl;
  itr(unique_primes) {
    if (primes[it] < 0)
      cout << pow(it, abs(primes[it])) << " ";
  }
}

/*
Author: Uttam Raj
Date: 2025-01-18
Problem: Problem Name/URL
*/
