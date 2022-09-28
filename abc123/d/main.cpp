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

int X, Y, Z, K;
vector<vector<ll>> cand(3);

bool check(ll x, const vector<ll>& AB) {
  ll count = 0;
  rep(c, 0, Z) {
    int idx = lower_bound(all(AB), x - cand[2][c]) - AB.begin();
    count += AB.size() - idx;
  }

  return K <= count;
}
void _main() {
  cin >> X >> Y >> Z >> K;
  vector<int> xyz = {X, Y, Z};
  rep(i, 0, 3) {
    rep(j, 0, xyz[i]) {
      ll a;
      cin >> a;
      cand[i].push_back(a);
    }
  }

  vector<ll> AB;
  rep(a, 0, X) { rep(b, 0, Y) AB.push_back(cand[0][a] + cand[1][b]); }
  sort(all(AB));

  ll ok = 0, bad = infl;
  while (ok + 1 != bad) {
    ll mid = (ok + bad) / 2;
    check(mid, AB) ? ok = mid : bad = mid;
  }

  reverse(all(AB));
  // sort(all(cand[2], greater<ll>()));

  vector<ll> ans;
  rep(c, 0, Z) {
    rep(ab, 0, AB.size()) {
      ll p = cand[2][c] + AB[ab];
      if (ok >= p) break;
      ans.push_back(p);
    }
  }

  while (ans.size() < K) ans.push_back(ok);

  assert(ans.size() == K);
  sort(all(ans), greater<ll>());
  for_each(ans.begin(), ans.end(), [](auto& x) { cout << x << endl; });
}
