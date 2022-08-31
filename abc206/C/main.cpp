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
  // 2 <=N<=3*10^5
  // Θ(N^2)ならOK,Θ(N^3)ならTLE

  cin >> N;
  map<int, int> A;

  rep(i, 0, N) {
    int m;
    cin >> m;
    A[m]++;
  }

  long long ans = (N * (N - 1)) / 2;
  fore(aa, A) { ans -= (aa.second * (aa.second - 1)) / 2; }
  cout << ans << endl;
}
