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
#include <atcoder/modint>
//
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>
//
using namespace atcoder;
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

int N;
ll P, Q;
string S;
bool is_coprime(ll a, ll b) { return gcd(a, b) == 1; }
void _main() {
  cin >> N >> P >> Q;
  modint::set_mod(P);
  vector<int> A(N);
  fore(i, A) cin >> i;

  int ans = 0;
  rep(i, 0, N) {
    rep(j, i + 1, N) {
      rep(k, j + 1, N) {
        rep(l, k + 1, N) {
          rep(m, l + 1, N) {
            modint a = 1;
            modint mul = a * A[i] * A[j] * A[k] * A[l] * A[m];
            if (mul == Q) ans++;
          }
        }
      }
    }
  }
  std::cout << ans << std::endl;
}
