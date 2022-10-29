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

int N, M, Q;
string S;
int idx_with_offset(int a, int offset) {
  a = (a - offset) % N;
  if (a < 0) a += N;
  return a;
}

void _main() {
  cin >> N >> Q;
  vector<int> A(N);
  fore(i, A) cin >> i;
  assert(A.size() == N);

  int offset = 0;
  rep(i, 0, Q) {
    int t, x, y;
    cin >> t >> x >> y;
    --x, --y;
    if (t == 1) {
      x = idx_with_offset(x, offset);
      y = idx_with_offset(y, offset);
      swap(A[x], A[y]);
    } else if (t == 2) {
      offset++;
    } else {
      std::cout << A[idx_with_offset(x, offset)] << std::endl;
    }
  }
}
