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

int N, M;
vector<int> P;
int check(vector<vector<bool>>& lamp, vector<bool>& sw) {
  bool ok = true;
  rep(i, 0, lamp.size()) {
    int on = 0;
    rep(j, 0, lamp[i].size()) {
      if (sw[j] & lamp[i][j]) on++;
    }

    if (on % 2 != P[i]) ok = false;
  }

  return ok;
}

int rec(vector<vector<bool>>& lamp, vector<bool> sw) {
  if (sw.size() == N) {
    return check(lamp, sw);
  }

  int result = 0;
  rep(i, 0, 2) {
    sw.push_back(i % 2 == 1);
    result += rec(lamp, sw);
    sw.pop_back();
  }

  return result;
}
void _main() {
  cin >> N >> M;  // <=10

  vector<vector<bool>> lamps(M, vector<bool>(N, false));
  fore(i, lamps) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int a;
      cin >> a;
      i[--a] = true;
    }
  }

  P.resize(M);
  fore(i, P) cin >> i;

  vector<bool> sw;
  cout << rec(lamps, sw) << endl;
}
