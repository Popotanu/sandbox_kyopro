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

// https://atcoder.jp/contests/abc071/tasks/arc081_a
int N;
string S;
void _main() {
  cin >> N;  // <=10e5

  map<ll, int> A;

  // 棒の長さをmapのindexにする

  // mapを逆順から見てく方法わからないから,
  // 棒の長さをマイナスとして扱う，答えだすときにプラスに戻す
  rep(i, 0, N) {
    ll a;
    cin >> a;
    A[-a]++;
  }

  ll b = 0, c = 0;
  fore(i, A) {
    if (i.second / 4) {
      b = i.first * -1;
      c = i.first * -1;
    } else if (i.second / 2) {
      if (b) swap(b, c);
      b = i.first * -1;
    }
    if (b && c) break;
  }

  ll ans = b * c;
  cout << ans << endl;
}
