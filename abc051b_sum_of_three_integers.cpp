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

// 0 <= x,y.z <= K
// x+y+z=Sなる組(x,y,z)は何通り？？
int K, S;
int main() {
  cin >> K >> S;

  int ans = 0;

  // 愚直に3重ループで全探索したらTLEした(2205ms)
  // K=2500のとき, K^3 > 10^9
  // という計算をぱっとできると良いね.コード書く前に.
  rep(x, 0, K + 1) {
    rep(y, 0, K + 1) {
      if (S - (x + y) <= K && S - (x + y) >= 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}
