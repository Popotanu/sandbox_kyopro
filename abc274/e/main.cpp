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
// using mint = modint998244353;
// using mint = modint1000000007;
// using mint = modint;
/* ------------------------------- */

// clang-format off

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

int N, M, Q;
double norm(const pair<int, int>& a, const pair<int, int>& b) {
  int dx = b.first - a.first, dy = b.second - a.second;
  return sqrt(1LL * dx * dx + 1LL * dy * dy);
}

void _main() {
  cin >> N >> M;
  int v = N + M + 1;
  vector<pair<int, int>> p(v, {0, 0});
  int v_bit = 1 << v;

  rep(i, 0, v - 1) cin >> p[i].first >> p[i].second;

  vector<vector<double>> dist(v, vector<double>(v, 0));
  rep(i, 0, dist.size()) { rep(j, 0, dist.size()) dist[i][j] = norm(p[i], p[j]); }
  assert(norm({0, 0}, {4, 0}) == 4.0);

  vector<double> spd(v_bit, 1);

  rep(b, 0, v_bit) {
    rep(i, 0, M) {
      // 街と宝の訪問状況のすべての組み合わせについて, 移動速度(所要時間計算の係数)をメモしてく.
      // bit列の宝の取得状況を表す部分列の,立ってるbitの数を数える
      // その数だけ移動速度が倍々になってく(= 移動時間が半分になってく)
      if (b >> (N + i) & 1) spd[b] /= 2;
    }
  }

  // bitDP(TSP)
  constexpr double infd = 1e18;
  vector<vector<double>> dp(v_bit, vector<double>(v, infd));
  dp[0][N + M] = 0;
  rep(b, 0, v_bit) {
    rep(i, 0, v) {
      if (dp[b][i] == infd) continue;

      rep(j, 0, v) if (~((b >> j) & 1)) {
        chmin(dp[b | 1 << j][j], dp[b][i] + dist[i][j] * spd[b]);
      }
    }
  }

  // 街をすべて回った状態
  int goal = ((1 << N) - 1) | 1 << (N + M);

  double ans = infd;
  rep(b, 0, v_bit) {
    // 点どうしを自由に行き来できるから自動的にハミルトン.
    // したがってゴールできないケースは考慮しなくていい.
    if ((b & goal) == goal) chmin(ans, dp[b][N + M]);
  }

  cout << fixed << setprecision(10);
  std::cout << ans << std::endl;
}
