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
string S;

vector<pair<char, int>> runLengthEncoding(string s) {
  int n = s.length();

  vector<pair<char, int>> res;
  char pre = s[0];
  int cnt = 1;
  rep(i, 1, n) {
    if (pre != s[i]) {
      res.push_back({pre, cnt});
      pre = s[i];
      cnt = 1;
    } else
      cnt++;
  }

  res.push_back({pre, cnt});
  return res;
}

void _main() {
  cin >> N >> S;
  vector<pair<char, int>> R = runLengthEncoding(S);

  vector<int> csR(R.size() + 1, 0);
  rep(i, 1, csR.size()) { csR[i] = csR[i - 1] + R[i - 1].second; }

  ll ans = 0;
  rep(i, 0, R.size() - 1) { ans += 1LL * R[i].second * (csR[csR.size() - 1] - csR[i + 1]); }
  std::cout << ans << std::endl;
}
