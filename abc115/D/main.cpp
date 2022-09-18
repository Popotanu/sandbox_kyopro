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

ll patties(int N, ll X, const vector<ll>& L, const vector<ll>& S) {
  if (N == 0) {
    return 1;
  }
  if (X == 1) {
    return 0;
  } else if (X <= L[N - 1] + 1) {
    return patties(N - 1, X - 1, L, S);
  } else if (X == L[N - 1] + 2) {
    return S[N - 1] + 1;
  } else if (X <= L[N - 1] * 2 + 2) {
    return patties(N - 1, X - L[N - 1] - 2, L, S) + S[N - 1] + 1;
  } else {
    return S[N - 1] * 2 + 1;
  }
}
// https://atcoder.jp/contests/abc115/tasks/abc115_d
int N;
string S;
void _main() {
  ll X;
  cin >> N >> X;

  // N (ただし1<=N)
  // 0: P
  // 1: B P P P B
  // 2: B BPPPB P BPPPB B
  // 3: B BBPPPBPBPPPBB P BBPPPBPBPPPBB B
  // L: B L-1 P L-1 B
  // 下             上

  // X=1:0
  // X=2...L_N-1 +1: Lv N-1の先頭から, X-1文字の中に含まれるPの個数
  // X= L_N-1 +2 : S_N-1 +1

  // 全探索+再帰でとく

  // Lvごとのバーガーの長さとパティの数,添字がレベル
  vector<ll> L(N + 1, 1), S(N + 1, 1);
  rep(i, 1, N + 1) {
    L[i] = L[i - 1] * 2 + 3;
    S[i] = S[i - 1] * 2 + 1;
  }
  std::cout << patties(N, X, L, S) << endl;
}
