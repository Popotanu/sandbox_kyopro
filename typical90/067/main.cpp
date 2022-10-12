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

string N;
int K;

ll to10(string n) {
  ll result = 0, x = 1;

  rrep(d, n.size() - 1, 0) {
    ll digit = (n[d] - '0');
    result += digit * x;
    x *= 8LL;
  }
  return result;
}

string to9(ll n) {
  if (n == 0) return "0";

  string result;
  while (n > 0) {
    int r = n % 9;
    if (r == 8) r = 5;
    result += r + '0';

    n /= 9;
  }
  return result;
}

void _main() {
  cin >> N >> K;

  rep(i, 0, K) {
    string N8 = to9(to10(N));
    reverse(all(N8));
    N = N8;
  }

  std::cout << N << std::endl;
}
