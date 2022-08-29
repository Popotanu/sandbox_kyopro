
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

int A, B, W;
int main() {
  cin >> A >> B >> W;
  W *= 1000;

  int min = 1e9;
  int max = 0;
  rep(i, 1, 1000 * W) {
    if (A * i <= W && B * i >= W) {
      min = std::min(min, i);
      max = std::max(max, i);
    }
  }

  if (max == 0) {
    cout << "UNSATISFIABLE";
  } else {
    cout << min << " " << max;
  }
  cout << endl;
}
