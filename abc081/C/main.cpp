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

  vector<int> bucket(N);
  rep(i, 0, N) {
    int a;
    cin >> a;
    bucket[a - 1]++;
  }

  sort(bucket.begin(), bucket.end());

  int ans = 0;
  rep(i, 0, (int)bucket.size() - K) { ans += bucket.at(i); }
  cout << ans << endl;
}
