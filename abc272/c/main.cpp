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

int N, M;
string S;

int ad(const vector<int>& v) {
  if (v.size() != 2) return -1;
  return v[0] + v[1];
}
void _main() {
  cin >> N;
  priority_queue<int> A;
  rep(i, 0, N) {
    int a;
    cin >> a;
    A.push(a);
  }

  vector<int> od, ev;

  // oo,ee
  while (!A.empty() && (od.size() < 2 || ev.size() < 2)) {
    int cur = A.top();
    A.pop();
    if (cur % 2 == 0 && ev.size() < 2) {
      ev.push_back(cur);
    } else if (cur % 2 == 1 && od.size() < 2) {
      od.push_back(cur);
    }
  }

  cout << max(ad(od), ad(ev)) << endl;
}
