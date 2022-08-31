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
int main() {
  // 1 <= N <=50
  // 1 <= S_i(ひとつの文字列) <=50
  // 2500かな？ a=2500として,  O(a^2*loga)はいける, O(a^3)はTLE

  cin >> N;

  vector<vector<int>> A(N, vector<int>(26));

  fore(a, A) {
    string s;
    cin >> s;
    fore(ss, s) a[ss - 'a']++;
  }

  // 行列？を縦に見て,'各文字がどれだけ共通してるか'を調べていく

  string ans = "";
  rep(i, 0, 26) {
    int m = 1e9;

    fore(a, A) { m = min(m, a[i]); }
    string s(m, 'a' + i);
    ans += s;
  }

  cout << ans << endl;
}
