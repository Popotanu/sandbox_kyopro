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

int N, K;
string A[1009];
int main() {
  cin >> N >> K;

  long long ans = 0;

  int c = 0;
  rep(i, 1, N + 1) {
    if (i % K == 0) c++;
    ans = 1LL * pow(c, 3);
  }

  c = 0;
  if (K % 2 == 0) {
    rep(i, 1, N + 1) if (i % K == K / 2) c++;

    ans += 1LL * pow(c, 3);
  }

  cout << ans << endl;
}
