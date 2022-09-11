
#include <bits/stdc++.h>

using namespace std;

// clang-format off
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
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

long long H, W;
int C, Q;
string A;
void _main() {
  cin >> H >> W >> C >> Q;

  stack<tuple<int, long long, int>> commands;
  // デフォルトは無色
  rep(i, 0, Q) {
    int t, c;
    long long n;
    cin >> t >> n >> c;
    c--;
    n--;
    commands.push(make_tuple(t, n, c));
  }

  vector<long long> colors(C);
  set<long long> used_w;
  set<long long> used_h;

  while (commands.size()) {
    tuple<int, long long, int> command = commands.top();
    int t, c;
    long long n;
    tie(t, n, c) = command;
    if (t == 1 && !used_w.count(n)) {
      // w
      colors[c] += W - used_h.size();
      used_w.insert(n);
    }
    if (t == 2 && !used_h.count(n)) {
      colors[c] += H - used_w.size();
      used_h.insert(n);
    }

    commands.pop();
  }

  fore(i, colors) { cout << i << " "; }
  cout << endl;
}
