#include <cmath>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
  bool isLeft = hand == "left";

  string answer = "";

  int lx = 0, ly = 0;
  int rx = 0, ry = 0;
  for (int n : numbers) {
    if (n == 1) {
      answer += 'L';
      lx = 0;
      ly = 3;
    } else if (n == 4) {
      answer += 'L';
      lx = 0;
      ly = 2;
    } else if (n == 7) {
      answer += 'L';
      lx = 0;
      ly = 1;
    } else if (n == 3) {
      answer += 'R';
      rx = 0;
      ry = 3;
    } else if (n == 6) {
      answer += 'R';
      rx = 0;
      ry = 2;
    } else if (n == 9) {
      answer += 'R';
      rx = 0;
      ry = 1;
    } else {
      int dx = 1;
      int dy = 0;
      if (n == 2) {
        dy = 3;
      } else if (n == 5) {
        dy = 2;
      } else if (n == 8) {
        dy = 1;
      }

      int ldist = abs(dx - lx) + abs(dy - ly);
      int rdist = abs(dx - rx) + abs(dy - ry);
      if (ldist > rdist) {
        answer += 'R';
        rx = dx;
        ry = dy;
      } else if (ldist < rdist) {
        answer += 'L';
        lx = dx;
        ly = dy;
      } else {
        if (isLeft) {
          answer += 'L';
          lx = dx;
          ly = dy;
        } else {
          answer += 'R';
          rx = dx;
          ry = dy;
        }
      }
    }
  }

  return answer;
}