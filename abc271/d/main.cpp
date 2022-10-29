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

int N, M, Q, S;
void _main() {
  cin >> N >> S;
  vector<int> A(N), B(N);
  rep(i, 0, N) { cin >> A[i] >> B[i]; }

  vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
  dp[0][0] = true;

  rep(i, 0, N) {
    rep(s, 0, S) {
      if (dp[i][s]) {
        if (s + A[i] <= S) dp[i + 1][s + A[i]] = true;
        if (s + B[i] <= S) dp[i + 1][s + B[i]] = true;
      }
    }
  }

  string ans(N, 'T');
  if (dp[N][S]) {
    rrep(i, N, 1) {
      if (S >= A[i - 1] && dp[i - 1][S - A[i - 1]]) {
        ans[i - 1] = 'H';
        S -= A[i - 1];
      } else {
        ans[i - 1] = 'T';
        S -= B[i - 1];
      }
    }

    std::cout << "Yes" << std::endl;
    std::cout << ans << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}
