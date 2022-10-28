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
#include <atcoder/modint>
//
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>
//
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

string LL, RR;

mint count_by_a_digit(unsigned long long l, unsigned long long r, int digit) {
  return mint(digit) * (l + r) * (r - l + 1) / 2;
}
void _main() {
  cin >> LL >> RR;
  ll dl = LL.size(), dr = RR.size();
  unsigned long long L = stoull(LL), R = stoll(RR);

  mint ans = 0;
  rep(d, dl, dr + 1) {
    unsigned long long maL = max(L, (unsigned long long)pow(10, d - 1));
    unsigned long long miR = min(R, (unsigned long long)pow(10, d) - 1);
    ans += count_by_a_digit(maL, miR, d);
  }
  std::cout << ans.val() << std::endl;
}
