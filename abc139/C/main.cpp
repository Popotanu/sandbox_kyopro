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
string A;
int main() {
  // N <= 10^5
  // H_i <= 10^9
  // ∴ Θ(N^2)ならばTLE
  cin >> N;
  vector<int> H(N);
  fore(h, H) { cin >> h; }

  // 単調非増加な区間の長さの最大を求める
  long long ans = 0, cur = 0;
  rep(i, 1, N) {
    if (H[i - 1] >= H[i]) {
      cur++;
    } else {
      ans = max(ans, cur);
      cur = 0;
    }
  }
  ans = max(ans, cur);
  cout << ans << endl;
}
