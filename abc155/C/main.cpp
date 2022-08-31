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
  // N <= 2*10^5より,  < O(N^2)でとく
  cin >> N;

  // mapはkey昇順で常にソートされる
  map<string, int> S;

  int ma = 0;
  rep(i, 0, N) {
    string s;
    cin >> s;
    S[s]++;
    ma = max(ma, S[s]);
  }

  fore(i, S) {
    if (i.second != ma) continue;
    cout << i.first << endl;
  }
}
