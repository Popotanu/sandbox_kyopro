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
string A;
int main() {
  cin >> A;
  vector<pair<char, int>> p;
  char prev = A[0];
  int count = 1;
  rep(i, 1, A.size()) {
    if (prev != A[i]) {
      p.push_back({prev, count});
      prev = A[i];
      count = 1;
    } else {
      count++;
    }
  }
  p.push_back({prev, count});

  fore(pair, p) { cout << pair.first << pair.second; }
  cout << endl;
}
