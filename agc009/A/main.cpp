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
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i] >> B[i]; }

  ll ans = 0;
  rrep(i, N - 1, 0) {
    A[i] += ans;

    // Z/B[i]Z のなかでA[i]を考えたときに，A[i]の逆元だけボタンを押せばいい
    ll r = A[i] % B[i];
    if (r) ans += (B[i] - r);
  }

  cout << ans << endl;
}

// clang-format off

/* めも

- AにMこの要素があるとする,最後の要素について考える
- $ A_m % B_m = B_{m}-1$のとき
  - (どこかで)m個目のスイッチを押さねばならない

- k手目に↑の状況で,かつ$ A_{m-1} % B_{m-1} = B_{m-1}-1$のとき
  - 目的を達成するためには,スイッチmとm-1をそれぞれ少なくとも1回は押さねばならない
  - スイッチmを先に押す場合(後ろ側のボタンから押す):
    - $A_m, A_{m-1}$がそれぞれインクリメントされる
    - 結果,k+1手目にどちらも 対応するBの倍数 となる.
      - 1手

  - スイッチm-1を先に押す場合(前側から押す):
    - k手目に$A_{m-1}$のみがインクリメントされ,B_{m-1}の倍数となる
    - $A_m$についても目的を達成するために,スイッチmを押す
      - このとき$A_m$ は $B_m$の倍数となるが
      - $ A_{m-1}$も同時にインクリメントされ,$B_{m-1}$の倍数+1となってしまう.
        - よって,更に$B_{m-1}-1$回スイッチm-1を押さねばならない
        - k+1+(b-1)回

- 同様の手順を踏むことにより,$A_m,A_{m-1}$が それぞれどのような数でも
  - 後ろ側から押す場合,結果は悪化しないことがわかる
    - (このへん雑)

  - ...はず

- 後ろ側のボタンから貪欲に押していく

*/

// clang-format on