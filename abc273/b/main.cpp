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

int K;
string X;
void _main() {
  cin >> X >> K;

  vector<int> xx(17, 0);  // 制約よりXの桁数はたかだか16
  fore(a, X) xx.push_back(a - '0');

  reverse(all(xx));
  rep(i, 0, K) {
    // 1. いま見てる桁を四捨五入する
    if (xx[i] >= 5) {
      xx[i + 1]++;
      xx[i] = 0;
    } else {
      xx[i] = 0;
    }

    // 2. 繰り上がり処理
    // 四捨五入の結果．上の桁が繰り上がることがある
    // listの各要素が1桁になるように処理する.
    rep(j, i + 1, xx.size()) {
      if (xx[j] < 10) continue;

      xx[j + 1]++;
      xx[j] %= 10;
    }
  }

  bool formatted = false;
  rrep(i, xx.size() - 1, 0) {
    if (!formatted && i != 0) {  // あたまの0は出力しない
      if (xx[i] == 0) continue;
    }

    cout << xx[i];
    if (!formatted) formatted = true;
  }
  cout << endl;
}
