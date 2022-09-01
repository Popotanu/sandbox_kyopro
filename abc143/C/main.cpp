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

int N;
string S;
int main() {
  // N <= 10^5より, Θ(N^2)ならばTLE.
  cin >> N >> S;

  // 1次元，2匹で消えるぷよぷよみたいなことする.
  // 同色2匹が隣接したら1匹になる
  // から，隣接する同色のぷよたちは結局1匹になる.

  int ans = 0;
  char prev;
  fore(s, S) {
    if (s == prev) continue;
    prev = s;
    ans++;
  }

  cout << ans << endl;
}
