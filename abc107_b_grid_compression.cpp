#include <bits/stdc++.h>

using namespace std;

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

// int N;

int H, W;
string A[101];

int check() {
  rep(y, 0, H) {
    int ok = 1;
    rep(x, 0, W) if (A[y][x] == '#') ok = 0;

    if (ok) {
      // y行目を最終行まで1行ずつ行変形する.
      // 最後にHをデクリメントする.
      // 結果出力時に最終行としてHの値を用いるから，Hをデクリメントすることは配列Aの行数を1行減らすのと同じと言える

      rep(yy, y + 1, H) swap(A[yy - 1], A[yy]);
      H--;
      return 1;
    }
  }

  rep(x, 0, W) {
    int ok = 1;
    rep(y, 0, H) if (A[y][x] == '#') ok = 0;
    if (ok) {
      // 列の消去.
      // いまx列目(0始まり)が全部.だった．
      // substr(開始位置,文字数(or 最後まで))を抜き出す.
      // よって,↓はyy行目のx文字目を削除するのと同じといえる.
      rep(yy, 0, H) A[yy] = A[yy].substr(0, x) + A[yy].substr(x + 1);
      W--;
      return 1;
    }
  }

  return 0;
}

int main() {
  cin >> H >> W;
  rep(i, 0, H) cin >> A[i];

  while (check())
    ;

  rep(i, 0, H) cout << A[i] << endl;
}
