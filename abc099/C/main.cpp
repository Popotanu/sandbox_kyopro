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

int N;
string S;
vector<int> dp;

int rec(int i) {
  if (dp[i] != inf) return dp[i];
  if (i == 0) return 0;

  int result = inf;
  chmin(result, rec(i - 1) + 1);

  int base6 = 6;
  while (i >= base6) {
    chmin(result, rec(i - base6) + 1);
    base6 *= 6;
  }

  int base9 = 9;
  while (i >= base9) {
    chmin(result, rec(i - base9) + 1);
    base9 *= 9;
  }

  return dp[i] = result;
}

void _main() {
  cin >> N;

  dp.assign(N + 1, inf);
  dp[0] = 0;

  std::cout << rec(N) << endl;
  dbg(dp[N]);
}
