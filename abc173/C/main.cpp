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
#define _GLIBCXX_DEBUG  // 空の構造に対して未定義な操作を行ったときに例外を投げる
#ifdef LOCAL
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
// #define dbg(x) true
#endif

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

// https://atcoder.jp/contests/abc173/tasks/abc173_c
int H, W, K;
string grid[6];
string gridd[6];
void _main() {
  cin >> H >> W >> K;
  rep(i, 0, H) cin >> grid[i];

  int ans = 0;
  rep(maskH, 0, 1 << H) {
    rep(maskW, 0, 1 << W) {
      // 1組ためすごとにgridをもとに戻す
      rep(gg, 0, H) gridd[gg] = grid[gg];

      // デバッグしやすいように白と赤を分けとく
      rep(y, 0, H) if (maskH & (1 << y)) rep(x, 0, W) gridd[y][x] = 'R';
      rep(x, 0, W) if (maskW & (1 << x)) rep(y, 0, H) gridd[y][x] = 'R';

      int count = 0;
      fore(gg, gridd) { fore(ss, gg) if (ss == '#') count++; }

      if (count == K) ans++;
    }
  }

  std::cout << ans << endl;
  // cout << rec(H - 1, W - 1, grid, kuro - K) << endl;
}
