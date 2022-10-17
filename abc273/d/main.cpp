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
  /* 1.準備とか*/
  cin >> H >> W >> ch >> cw >> N;

  // 壁全体の情報を2種類の持ち方で持つ．map.
  // wallsFixedH[h]={w1,w2,w3...}
  // wallsFixedW[w]={h1,h2,h3...}
  // 2つのmapは同じ情報が入ってるけど,軸1つ固定して持つことで衝突判定が楽になる.
  map<int, vector<int>> wallsFixedH, wallsFixedW;
  rep(i, 0, N) {
    int h, w;
    cin >> h >> w;
    wallsFixedH[h].push_back(w);
    wallsFixedW[w].push_back(h);
  }

  // lower_boundしたい
  fore(w, wallsFixedH) sort(all(w.second));
  fore(w, wallsFixedW) sort(all(w.second));

  /* 2.クエリにこたえる */
  cin >> Q;
  rep(q, 0, Q) {
    char d;
    int l;
    cin >> d >> l;

    switch (d) {
      {
        case 'U':
          // 障害物(壁)判定. 上に移動するからx軸は固定して考えてOK
          int wallH = 0;  // 0で初期化することで,グリッド外の衝突判定も兼ねる.
          auto itW = wallsFixedW.find(cw);
          if (itW == wallsFixedW.end()) {
            ch = max(ch - l, wallH + 1);
            break;
          }

          vector<int>& wHs = itW->second;  // 値のコピー避ける

          // いま↑に行きたい.壁のうち，現在地よりyの小さいものたちを取ってくる
          auto it = lower_bound(all(wHs), ch);
          if (it != wHs.begin()) {
            // e.g)いまy=3にいる,壁たちのy座標={1,2,4,5}とする
            // {1,2,| 4,5} ←lower_boundで取れるポインタ
            // ほしいのは2を指すポインタ,の値. だから1つ戻す.
            it--;

            // it--したおかげでend()指してた場合でもバグらなくて嬉しい
            wallH = *it;
          }
          ch = max(ch - l, wallH + 1);  // 壁の手前orグリッドの端まで動ける
          break;
      }

      {
        case 'D':
          int wallH = H + 1;
          auto itW = wallsFixedW.find(cw);
          if (itW == wallsFixedW.end()) {
            ch = min(ch + l, wallH - 1);
            break;
          }

          vector<int>& wHs = itW->second;
          auto itH = upper_bound(all(wHs), ch);
          if (itH != wHs.end()) wallH = *itH;

          ch = min(ch + l, wallH - 1);
          break;
      }

      {
        case 'L':
          int wallW = 0;
          auto itH = wallsFixedH.find(ch);
          if (itH == wallsFixedH.end()) {
            cw = max(cw - l, wallW + 1);
            break;
          }

          vector<int>& wWs = itH->second;
          auto itW = lower_bound(all(wWs), cw);
          if (itW != wWs.begin()) itW--, wallW = *itW;
          cw = max(cw - l, wallW + 1);
          break;
      }

      {
        case 'R': {
          int wallW = W + 1;
          auto itH = wallsFixedH.find(ch);

          if (itH == wallsFixedH.end()) {
            cw = min(cw + l, wallW - 1);
            break;
          }

          vector<int>& wWs = itH->second;
          auto itW = upper_bound(all(wWs), cw);
          if (itW != wWs.end()) wallW = *itW;
          cw = min(cw + l, wallW - 1);
          break;
        }
        default:
          assert(1 == 2);
          break;
      }
    }

    cout << ch << " " << cw << endl;
  }
}
