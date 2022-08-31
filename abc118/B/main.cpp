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
  vector<int> suki(M);
  rep(i, 0, N) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int a;
      cin >> a;
      suki.at(a - 1)++;
    }
  }

  int ans =
      accumulate(suki.begin(), suki.end(), 0, [](int acc, const auto &current) {
        return acc + (current == N ? 1 : 0);
      });
  cout << ans << endl;
}
