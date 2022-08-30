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

double a, b, d;
string A[1009];
int main() {
  //[-1000,1000]
  cin >> a >> b >> d;

  double theta = d * (M_PI / 180.0);
  double x, y;

  // c++のsin関数とcos関数ググった
  x = cos(theta) * a + -sin(theta) * b;
  y = sin(theta) * a + cos(theta) * b;

  // ↓で精度を指定する方法をググった
  cout << fixed << setprecision(10);

  cout << x << " " << y << endl;
}
