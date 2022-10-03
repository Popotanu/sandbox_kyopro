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
  cin >> S;

  vector<bool> dp(S.size() + 1, false);
  dp[0] = true;

  rep(i, 5, S.size() + 1) {
    if (i >= 5 && dp[i - 5]) {
      if (S.substr(i - 5, 5) == "dream" || S.substr(i - 5, 5) == "erase") {
        dp[i] = true;
      }
    }
    if (i >= 6 && dp[i - 6]) {
      if (S.substr(i - 6, 6) == "eraser") {
        dp[i] = true;
      }
    }
    if (i >= 7 && dp[i - 7]) {
      if (S.substr(i - 7, 7) == "dreamer") {
        dp[i] = true;
      }
    }
  }

  cout << (dp[S.size()] ? "YES" : "NO") << endl;
}
