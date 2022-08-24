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

string bingo(vector<vector<int>> result) {
  rep(i, 0, 3) {
    if (result.at(i).at(0) + result.at(i).at(1) + result.at(i).at(2) == 3 ||
        result.at(0).at(i) + result.at(1).at(i) + result.at(2).at(i) == 3) {
      return "Yes";
    }
  }

  if (result.at(0).at(0) + result.at(1).at(1) + result.at(2).at(2) == 3)
    return "Yes";
  if (result.at(0).at(2) + result.at(1).at(1) + result.at(2).at(0) == 3)
    return "Yes";

  return "No";
}

int main() {
  vector<vector<int>> b(3, vector<int>(3));
  vector<vector<int>> result(3, vector<int>(3));
  fore(i, b) fore(j, i) cin >> j;

  cin >> N;

  rep(i, 0, N) {
    int a;
    cin >> a;
    rep(j, 0, 3) {
      rep(k, 0, 3) {
        if (a == b.at(j).at(k)) {
          result.at(j).at(k) = 1;
          continue;
        }
      }
    }
  }

  cout << bingo(result) << endl;
}
