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

int H, W;
void _main() {
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  int sumA = 0, sumB = 0;
  fore(i, A) fore(j, i) cin >> j, sumA += j;
  fore(i, B) fore(j, i) cin >> j, sumB += j;
  assert(A.size() == H);

  if (abs(sumB - sumA) % 2 != 0) {
    std::cout << "No" << std::endl;
    return;
  }

  int ans = 0;
  rep(h, 0, H - 1) {
    rep(w, 0, W - 1) {
      int diff = B[h][w] - A[h][w];
      ans += abs(diff);
      rep(i, 0, 2) rep(j, 0, 2) A[h + i][w + j] += diff;
    }
  }

  if (A != B) {
    std::cout << "No" << std::endl;
    return;
  }
  std::cout << "Yes" << std::endl;
  std::cout << ans << std::endl;
}
