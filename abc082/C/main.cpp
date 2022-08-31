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
string A[1009];
int main() {
  // N≤10^5より < O(N^2)で解く
  cin >> N;

  map<int, int> a;
  rep(i, 0, N) {
    int aa;
    cin >> aa;
    a[aa]++;
  }

  if (!a.size()) {
    cout << 0 << endl;
    return 0;
  }

  // 増やしてはいけない.減らすだけ
  int ans = 0;
  fore(i, a) { ans += i.first <= i.second ? i.second - i.first : i.second; }
  cout << ans << endl;
}
