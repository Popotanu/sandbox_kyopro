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

// index が条件を満たすかどうか
bool isOK(const vector<ll>& v, int index, ll goal) {
  if (v[index] >= goal)
    return true;
  else
    return false;
}

int binary_search(const vector<ll>& v, ll goal) {
  int ng = -1;
  int ok = (int)v.size();

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (isOK(v, mid, goal))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}
void _main() {
  cin >> N;
  vector<ll> A(N);
  fore(i, A) cin >> i;
  assert(A.size() == N);

  vector<ll> cs(2 * N + 1, 0);
  rep(i, 1, cs.size()) { cs[i] = cs[i - 1] + A[(i - 1) % N]; }
  if (cs[N] % 10 != 0) {
    std::cout << "No" << std::endl;
    return;
  }

  rep(l, 0, N + 1) {
    ll goal = cs[l] + cs[N] / 10;
    int idx = binary_search(cs, goal);
    if (cs[idx] == goal) {
      std::cout << "Yes" << std::endl;
      return;
    }
  }
  std::cout << "No" << std::endl;
}
