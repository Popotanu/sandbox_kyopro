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
  cin >> N;

  map<string, int> s;
  rep(i, 0, N) {
    string ss;
    cin >> ss;
    sort(all(ss));
    s[ss]++;
  }

  int ans = accumulate(s.begin(), s.end(), 0, [](int acc, const auto &current) {
    if (current.second < 2) return acc;
    return acc + (current.second * (current.second - 1)) / 2;
  });

  cout << ans << endl;
}
