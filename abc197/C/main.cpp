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

int N;
string S;

ll calc(const vector<ll>& A, const vector<bool> pos) {
  ll res = A[0];
  rep(i, 1, N) {
    if (pos[i - 1]) {
      res ^= A[i];
    } else {
      res |= A[i];
    }
  }

  return res;
}
ll rec(const vector<ll>& A, vector<bool> pos_or) {
  if (pos_or.size() == N - 1) {
    return calc(A, pos_or);
  }
  ll result = infl;
  rep(i, 0, 2) {
    pos_or.push_back(i);
    chmin(result, rec(A, pos_or));
    pos_or.pop_back();
  }

  return result;
}

void _main() {
  cin >> N;  //<=20
  // 仕切りが最大19個.bit全探索ぽい感じでまにあいそう.
  vector<ll> A(N);
  fore(i, A) cin >> i;

  vector<bool> pos_or;
  cout << rec(A, pos_or) << endl;
}
