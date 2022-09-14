#include <bits/stdc++.h>

using namespace std;

// clang-format off
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
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

int N;
string S;
void _main() {
  cin >> S;

  map<char, int> c, chars;
  int su = 0;
  int rr = 0;
  set<char> r;
  fore(i, S) c[i]++;

  fore(i, c) {
    su += i.second / 2;
    rr += i.second % 2;
  }

  if (rr == 0) {
    cout << S.size() << endl;
    return;
  }

  int ans = su / rr;
  if (ans == 0) {
    ans = 1;
  } else {
    ans = 1 + ans * 2;
  }

  cout << ans << endl;
}
