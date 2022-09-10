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
  cin >> N >> S;

  int ans = 0;
  vector<int> ww(N + 1), ee(N + 2);
  rep(i, 0, N) {
    ww[i + 1] = ww[i] + (S[i] == 'W' ? 1 : 0);
    ee[i + 1] = ee[i] + (S[N - 1 - i] == 'E' ? 1 : 0);
  }
  reverse(all(ee));

  int gomen = 10e6;
  rep(i, 1, N + 1) { chmin(gomen, ww[i - 1] + ee[i + 1]); }

  cout << gomen << endl;
}
