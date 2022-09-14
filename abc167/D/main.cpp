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

int N;
ll obsession;
string A;
void _main() {
  cin >> N >> obsession;

  // x_i+1 = σ(x_i) = A[x_i]
  // 最初のxをx=0として，obsession回σでうつすと どの要素にいる？？

  // e.g.1)
  // 4 5
  // 3 2 4 1
  // =>4

  // (全単射じゃないから置換じゃないけど)
  // 巡回置換の積のようなものを考えて,各項ごとに分ければいいかな？
  // 始点が0で固定されてるから, 0はじまりの巡回だけ考えれば良さそう

  // テレポでたどる町をlistに記録してく.walkとする.
  // i回目のテレポでwalk[i]にいる.
  // ただし，0回目としてwalk[0] = 0 にしておく.

  // 1.walk.size() == Nになったとき:
  //   walkは全部の町の集合を包む.
  //   全部の町に1回ずつ行ったあと, 0に戻る.ループする.
  //   walk[obsession % N]を取ればいい.

  // 2. j回目のテレポで，walk[j] == j になった:
  //   j回目以降のテレポはずっと今いる街に飛び続ける.かわいそう.
  //    - walk[obsession] (obsession<j)
  //    - walk[j] (j <= obsession)

  // 3. 2は満たさないけど, j回目のテレポで以前行った町Aに戻った:
  //    (かわいそうって思ったけど現実とそう変わらない事に気づいた.)
  //
  //    Aを最初に訪れたのがk回目とする．つまりwalk[k] == A
  //    [walk[k], walk[j-1]]でループし続ける.
  //    - walk[obsession] (obsession<j)
  //    - walk[k + (obsession-k) % (ループに含まれる街の数)]

  // 巡回を調べるのにO(N)
  // N<=2*10^5だからいけそう
  // 行った町の検索がしんどい. walkとは別に setで行った町の集合を持つことにする.

  vector<int> A(N);
  fore(i, A) {
    int b;
    cin >> b;
    i = b - 1;
  }

  vector<int> walk;
  set<int> visited;
  walk.push_back(0);
  visited.insert(0);

  int be = 0;
  int now = 0;
  rep(i, 1, N) {
    int next = A[now];

    if (next == now || visited.count(next)) {
      be = distance(walk.begin(), find(all(walk), next));
      break;
    }

    walk.push_back(next);
    visited.insert(next);
    now = next;
  }

  int ans = 0;

  if (walk.size() == N) {
    ans = walk[obsession % N];
  } else if (obsession < be) {
    ans = walk[obsession];
  } else {
    ans = walk[be + (obsession - be) % (walk.size() - be)];
  }

  cout << ++ans << endl;
}
