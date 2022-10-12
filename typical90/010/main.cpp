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

int N, M, Q;
void _main() {
  cin >> N;
  vector<vector<int>> P(2);
  rep(i, 0, N) {
    int c, p;
    cin >> c >> p;
    if (c == 1) {
      P[0].push_back(p);
      P[1].push_back(0);
    } else {
      P[0].push_back(0);
      P[1].push_back(p);
    }
  }

  vector<vector<int>> cumsum(2, vector<int>(N + 1, 0));
  rep(i, 0, 2) {
    rep(j, 1, cumsum[i].size()) {
      cumsum[i][j] = cumsum[i][j - 1] + P[i][j - 1];
    }
  }

  cin >> Q;
  rep(q, 0, Q) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << cumsum[0][r] - cumsum[0][l] << " " << cumsum[1][r] - cumsum[1][l]
         << endl;
  }
}
