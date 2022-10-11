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

int N, L, K;
vector<int> A;
bool isOK(int obj) {
  int remain = K;
  int len = 0;

  rep(i, 1, N + 2) {
    len += A[i] - A[i - 1];
    if (len >= obj) {
      remain--;
      len = 0;
    }
    if (remain == -1) return true;
  }
  return false;
}

int binary_search(int l, int r) {
  int ok = l;
  int ng = r;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (isOK(mid))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

void _main() {
  cin >> N >> L >> K;
  A.resize(N + 2);
  A[0] = 0;

  rep(i, 0, N) {
    int a;
    cin >> a;
    A[i + 1] = a;
  }
  A[N + 1] = L;

  cout << binary_search(1, L) << endl;
}
