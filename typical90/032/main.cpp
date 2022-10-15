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
string S;
void _main() {
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  fore(aa, A) fore(a, aa) cin >> a;

  cin >> M;
  vector<vector<bool>> G(N, vector<bool>(N, false));
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u][v] = true;
    G[v][u] = true;
  }

  vector<int> P(N);
  rep(i, 0, N) { P[i] = i; }
  int ans = inf;

  do {
    int elapse = 0;
    bool kirai = false;

    rep(i, 0, N) {
      elapse += A[P[i]][i];
      if (i < N - 1 && G[P[i]][P[i + 1]]) kirai = true;
    }

    if (!kirai) chmin(ans, elapse);
  } while (next_permutation(all(P)));

  std::cout << (ans == inf ? -1 : ans) << std::endl;
}
