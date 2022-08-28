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

// N 個の整数 A 1 ​ , A 2 , ⋯, A N があります。
// この中から 5 個を選ぶ方法のうち、これら 5 個の整数の積を Pで割ると
// Q 余るようなものが何通りあるか求めてください。

int N, P, Q;
int main() {
  cin >> N >> P >> Q;
  vector<int> a(N);
  fore(i, a) {
    // int aa;
    // cin >> aa;
    // i = aa % P;
    cin >> i;
  }

  int ans = 0;

  rep(i, 0, N) {
    rep(j, 0, i) {
      rep(k, 0, j) {
        rep(l, 0, k) {
          rep(m, 0, l) {
            if ((1LL * a[i] * a[j] % P * a[k] % P * a[l] % P * a[m] % P) == Q)
              ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
}
