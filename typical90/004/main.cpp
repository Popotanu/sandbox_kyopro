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

int H, W;
string S;
void _main() {
  cin >> H >> W;

  vector<vector<int>> A(H, vector<int>(W));
  fore(i, A) fore(j, i) cin >> j;

  vector<int> sumH(H), sumW(W);
  rep(i, 0, H) rep(j, 0, W) sumH[i] += A[i][j];
  rep(i, 0, W) rep(j, 0, H) sumW[i] += A[j][i];

  vector<vector<int>> ans(H, vector<int>(W));
  rep(h, 0, H) {
    rep(w, 0, W) { ans[h][w] = sumH[h] + sumW[w] - A[h][w]; }
  }

  fore(a, ans) {
    for_each(a.begin(), a.end(), [](auto& x) { cout << x << " "; });
    cout << endl;
  }
}
