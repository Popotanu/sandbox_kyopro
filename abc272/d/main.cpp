#include <bits/stdc++.h>

using namespace std;

/* -------------ACL--------------- */
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
//
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
//
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>
//
// using namespace atcoder;
/* ------------------------------- */

// clang-format off
#define LOCAL

#ifdef LOCAL
  #define _GLIBCXX_DEBUG  // 配列外参照をしたときにエラーをあげる(未定義な動作の代わりに)
  #define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
#else
  #define dbg(x) true
#endif

void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

int N, M;
string S;

void _main() {
  cin >> N >> M;

  // N*N, sqrtM
  vector<vector<vector<pair<int, int>>>> G(N,
                                           vector<vector<pair<int, int>>>(N));

  set<pair<int, int>> distXY;

  // Nはたかだか400だから,次の行き先は全探索で求めてOK．
  // 浮動小数点つかいたくない.
  rep(x, 0, N + 1) {
    rep(y, 0, N + 1) {
      if (x * x + y * y == M) {
        distXY.insert({x, y});
        distXY.insert({-x, y});
        distXY.insert({x, -y});
        distXY.insert({-x, -y});
      }
    }
  }

  rep(x, 0, N) {
    rep(y, 0, N) {
      fore(d, distXY) {
        int nx = x + d.first;
        int ny = y + d.second;
        if (min(nx, ny) >= 0 && max(nx, ny) < N) {
          G[x][y].push_back({nx, ny});
        }
      }
    }
  }

  vector<vector<int>> dist(N, vector<int>(N, -1));
  dist[0][0] = 0;
  queue<pair<int, int>> que;
  que.push({0, 0});

  while (!que.empty()) {
    pair<int, int> cur = que.front();
    que.pop();

    for (auto next : G[cur.first][cur.second]) {
      if (dist[next.first][next.second] == -1) {
        dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
        que.push({next.first, next.second});
      }
    }
  }

  for (const auto& el : dist) {
    for (const auto& e : el) {
      cout << e << " ";
    }
    cout << endl;
  }
}
