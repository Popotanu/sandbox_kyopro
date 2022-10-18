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

int H, W, N, ch, cw, Q;
void _main() {
  cin >> H >> W >> ch >> cw >> N;
  map<int, vector<int>> wFixedH, wFixedW;
  rep(i, 0, N) {
    int h, w;
    cin >> h >> w;
    wFixedH[h].push_back(w);
    wFixedW[w].push_back(h);
  }
  fore(w, wFixedH) {
    // グリッドの外枠を壁と同一視する
    // これにより壁と外枠の衝突判定を1つの処理でできる
    w.second.push_back(0);
    w.second.push_back(W + 1);
    sort(all(w.second));
  }
  fore(w, wFixedW) {
    w.second.push_back(0);
    w.second.push_back(H + 1);
    sort(all(w.second));
  }

  cin >> Q;
  rep(i, 0, Q) {
    char d;
    int l;
    cin >> d >> l;

    if (d == 'U') {
      int border = 1;
      auto itW = wFixedW.find(cw);
      if (itW != wFixedW.end()) {
        auto itH = lower_bound(all(itW->second), ch);
        itH--, border = (*itH) + 1;
      }
      ch = max(ch - l, border);

    } else if (d == 'D') {
      int border = H;
      auto itW = wFixedW.find(cw);
      if (itW != wFixedW.end()) {
        auto itH = lower_bound(all(itW->second), ch);
        border = (*itH) - 1;
      }
      ch = min(ch + l, border);

    } else if (d == 'L') {
      int border = 1;
      auto itH = wFixedH.find(ch);
      if (itH != wFixedH.end()) {
        auto itW = lower_bound(all(itH->second), cw);
        itW--, border = (*itW) + 1;
      }
      cw = max(cw - l, border);

    } else if (d == 'R') {
      int border = W;
      auto itH = wFixedH.find(ch);
      if (itH != wFixedH.end()) {
        auto itW = lower_bound(all(itH->second), cw);
        border = (*itW) - 1;
      }
      cw = min(cw + l, border);

    } else {
      assert(1 == 2);
    }

    cout << ch << " " << cw << endl;
  }
}
