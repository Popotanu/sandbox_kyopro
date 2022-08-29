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

int N, M;
string A[1009];
int main() {
  cin >> N >> M;
  vector<int> S(M);
  vector<int> C(M);

  rep(i, 0, M) {
    cin >> S.at(i);
    cin >> C.at(i);
    S.at(i)--;
  }

  // 全探索
  rep(i, 0, 1000) {
    string s = to_string(i);

    // 指定された桁数以外の値なら，メインの処理をするまえに弾いちゃえばいい
    if (s.length() != N) continue;

    bool found = true;
    rep(j, 0, M) rep(k, 0, N) {
      // 指定された桁が指定された数字以外なら今回のiは求める値ではない.
      if (k == S[j] && (s[k] - '0') != C[j]) found = false;
    }

    if (found) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
