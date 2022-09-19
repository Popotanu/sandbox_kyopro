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
#define _GLIBCXX_DEBUG  // 空の構造に対して未定義な操作を行ったときに例外を投げる
#ifdef LOCAL
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
// #define dbg(x) true
#endif

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

int N;
string S;
void _main() {
  cin >> S;  // <=10
  vector<char> ss;
  fore(s, S) ss.push_back(s);

  // e.g) 1  2  3  4  5
  //        +  +  +  +

  ll ans = 0;
  int siz = ss.size();
  vector<ll> terms;
  string di;
  rep(mask, 0, 1 << (siz - 1)) {
    terms.clear();
    di = "";
    rep(i, 0, siz) {
      di += ss[i];
      if (mask & (1 << i)) {
        terms.push_back(stoll(di));
        di = "";
      }
    }

    terms.push_back(stoll(di));

    ans += accumulate(
        terms.begin(), terms.end(), 0LL,
        [](ll acc, const auto& current) { return 1LL * acc + current; });
  }

  cout << ans << endl;
}
