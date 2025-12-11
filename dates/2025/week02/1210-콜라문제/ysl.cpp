#include <cmath>

using namespace std;

int solution(int a, int b, int n) {
  int sum = 0;
  while (n >= a) {
    int left = n % a;
    int inc = floor(n / a) * b;
    sum += inc;
    n = inc + left;
  }
  return sum;
}