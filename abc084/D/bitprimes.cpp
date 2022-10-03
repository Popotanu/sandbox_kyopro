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

int N = 10e5, M, Q;
string S;
vector<bool> is_prime;
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= sqrt(N); i++) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= N; j += i) is_prime[j] = false;
    }
  }
}

// =================================
vector<int> makeBitPrimes(int n) {
  vector<int> v(n + 1, 1);
  v[0] = v[1] = 0;
  rep(i, 2, sqrt(n)) {
    if (v[i]) {
      for (int j = 0; i * (j + 2) < n; j++) v[i * (j + 2)] = 0;
    }
  }
  return v;
}
// =================================

void _main() {
  cin >> Q;
  is_prime.resize(N + 1, true);
  sieve();

  vector<int> summ(N + 1, 0);
  rep(i, 1, summ.size()) {
    bool like17 = is_prime[i] && is_prime[(i + 1) / 2];
    summ[i] = summ[i - 1] + like17;
  }

  // =================================
  assert(summ[0] == 0);
  assert(Q < 3 || summ[3] == 1);
  // =================================

  // dbg(summ[N]);
  rep(i, 0, Q) {
    int l, r;
    cin >> l >> r;
    std::cout << summ[r] - summ[l - 1] << std::endl;
  }
}
