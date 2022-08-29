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

int main() {
  int A, B, C;
  int X, Y;

  cin >> A >> B >> C >> X >> Y;

  // 最初に全部ABピザで賄おうとする
  // 1枚ずつABピザを減らして，その分をAピザBピザで補う
  // ABピザの初期枚数:max(X,Y)*2枚
  // から0枚までABピザを1枚ずつ減らし，価格の合計のminをとる
  int ans = C * max(X, Y) * 2;
  rrep(i, max(X, Y), 0) {
    int c = C * i * 2;
    int a = A * max(0, X - i);
    int b = B * max(0, Y - i);
    ans = min(ans, a + b + c);
  }

  cout << ans << endl;
}
