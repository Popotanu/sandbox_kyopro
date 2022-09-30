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

int N, M;
string S;
void _main() {
  cin >> N;

  vector<int> A(N);
  fore(i, A) cin >> i;
  assert(A.size() == N);

  sort(all(A));

  vector<bool> seen(N, false);
  int ans = 0;
  rrep(ex, 30, 0) {
    int idx_cand = N - 1;

    rep(i, 0, N) {
      if (seen[i]) continue;

      while (idx_cand > i &&
             (A[i] + A[idx_cand] > (1 << ex) || seen[idx_cand])) {
        --idx_cand;
      }

      if (i == idx_cand) break;
      if (A[i] + A[idx_cand] == (1 << ex)) {
        seen[i] = seen[idx_cand] = true;
        ans++;
      }
    }
  }

  cout << ans << endl;
}

// clang-format off

/*

- 大きい順で，自分より値の小さい相手と貪欲にペアを組めば最適解が得られることをしめす.
- 制約より$A_i \gt 0$に注意する

- あるA_iについて，A_i以下であり，かつA_iとの和が2べきになる正整数A_jはたかだかひとつ.
      - $A_i + A_j = 2^m$
      - $A_j = 2^m - A_i$

    - 2^mの次の2べきは
      - $2^{m+1} = 2(A_i + A_j)$

    - $2^{m+1} $について，A_iのペア相手 $ A_k \gt A_j$は
      - $ 2(A_i+A_j) = A_i + A_k$
      - $ A_k = A_i + 2A_j$
      - $A_j < 0$より$A_k \gt A_i$

    - よって↑の主張が成り立つ

- よって，大きい順に2ベキを考えていく場合
  - 数$A_i,A_j$が同じペア相手$A_k \leq A_i,A_j$を共有していたとしても
  - $A_iとA_j$のどちらが先に$A_k$を取っても,マッチングの数は同じになる

- したがって貪欲法が使える.

*/