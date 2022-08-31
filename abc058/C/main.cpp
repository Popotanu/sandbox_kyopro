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
  // 1 <= N <=50
  // 1 <= S_i(ひとつの文字列) <=50
  // 2500かな？ a=2500として,  O(a^2*loga)はいける, O(a^3)はTLE

  cin >> N;
  map<char, int> S;

  string a;
  cin >> a;
  fore(i, a) S[i]++;

  rep(i, 1, N) {
    string b;
    cin >> b;
    map<char, int> T;
    fore(bb, b) { T[bb]++; }
    fore(ss, S) { ss.second = min(ss.second, T[ss.first]); }
  }

  string ans = "";

  fore(i, S) {
    string tanu(i.second, i.first);
    ans += tanu;
  }

  cout << ans << endl;
}
