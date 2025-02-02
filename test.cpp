#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

void solve() {
  int a;
  cin >> a;
  while (a--) {
    int b, x, y, c, d;
    cin >> b >> x >> y >> c;

    vector<vector<int>> z(b + 1);
    for (int i = 0; i < c; ++i) {
      int d, e;
      cin >> d >> e;
      z[d].push_back(e);
      z[e].push_back(d);
    }

    cin >> d;
    vector<vector<int>> w(b + 1);
    for (int i = 0; i < d; ++i) {
      int e, f;
      cin >> e >> f;
      w[e].push_back(f);
      w[f].push_back(e);
    }

    vector<bool> v(b + 1, false);
    for (int f = 1; f <= b; ++f) {
      set<int> s(w[f].begin(), w[f].end());
      for (int nb : z[f]) {
        if (s.count(nb)) {
          v[f] = true;
          break;
        }
      }
    }

    const long long INF = LLONG_MAX;
    vector<vector<long long>> dist(b + 1, vector<long long>(b + 1, INF));
    dist[x][y] = 0;

    priority_queue<tuple<long long, int, int>,
                   vector<tuple<long long, int, int>>, greater<>>
        pq;
    pq.push({0, x, y});

    long long ans = -1;

    while (!pq.empty()) {
      auto [d, g, h] = pq.top();
      pq.pop();

      if (d != dist[g][h])
        continue;
      if (g == h && v[g]) {
        ans = d;
        break;
      }

      for (int ng : z[g]) {
        for (int nh : w[h]) {
          long long nd = d + abs(ng - nh);
          if (nd < dist[ng][nh]) {
            dist[ng][nh] = nd;
            pq.push({nd, ng, nh});
          }
        }
      }
    }

    cout << ans << endl;
  }
}

int main() {
  solve();
  return 0;
}
