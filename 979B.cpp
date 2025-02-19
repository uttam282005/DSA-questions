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
const int N = 1;

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

void solve() {
  int n;
  cin >> n;

  map<char, int> kuroo;
  map<char, int> shiroo;
  map<char, int> katie;

  string kur, shi, kat;
  cin >> kur >> shi >> kat;

  int m = kur.size();

  rep(i, 0, m) {
    kuroo[kur[i]]++;
    shiroo[shi[i]]++;
    katie[kat[i]]++;
  }

  int max_kuroo = 0, max_shiroo = 0, max_katie = 0;
  for (auto &[ch, cnt] : kuroo)
    max_kuroo = max(max_kuroo, cnt);
  for (auto &[ch, cnt] : shiroo)
    max_shiroo = max(max_shiroo, cnt);
  for (auto &[ch, cnt] : katie)
    max_katie = max(max_katie, cnt);

  int opsleftkuroo = abs(min(0, m - max_kuroo - n)) % 2;
  int opsleftshiroo = abs(min(0, (m - max_shiroo) - n)) % 2;
  int opsleftkatie = abs(min(0, (m - max_katie) - n)) % 2;

  debug(n - (m - max_katie));

  ll kurscore = min(m, max_kuroo + n);
  ll shiscore = min(m, max_shiroo + n);
  ll katscore = min(m, max_katie + n);

  kurscore -= opsleftkuroo;
  shiscore -= opsleftshiroo;
  katscore -= opsleftkatie;

  ll maxscore = max({kurscore, shiscore, katscore});

  int same =
      (kurscore == maxscore) + (shiscore == maxscore) + (katscore == maxscore);

  if (same >= 2) {
    cout << "Draw\n";
    return;
  }

  if (kurscore > shiscore && kurscore > katscore) {
    cout << "Kuro\n";
  } else if (shiscore > kurscore && shiscore > katscore) {
    cout << "Shiro\n";
  } else {
    cout << "Katie\n";
  }
}

/*
Author: Uttam Raj
Date: 2025-02-17
Problem: Problem Name/URL
*/
