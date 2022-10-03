#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 rng(rd());

using namespace std;
const int e5 = 10e5;
const int e9 = 10e9;
const long long e18 = 10e18;

int randint(int lo, int hi) {
  // lo 以上 hi 以下の乱数を返す
  return std::uniform_int_distribution<int>(lo, hi)(rng);
}

int main() {
  // ここに条件書く
  int N = randint(1, 2000);
  int H = 1000 * randint(1, 1000);
  std::cout << N << " " << H << endl;

  // for (int i = 0; i < e5; i++) {
  //   int a = randint(1, e9);
  //   int b = randint(a, e9);
  //   cout << a << " " << b << endl;
  // }
}
