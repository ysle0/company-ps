#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> to_map(int len, vector<int> const &src) {
  vector<string> chs;
  vector<string> ret;
  chs.reserve(len);
  ret.reserve(len);

  for (int e : src) {
    chs.clear();

    // 몫이 1이 될때까지 이진수 계산 반복
    while (e >= 1) {
      int left = e % 2;
      chs.push_back(to_string(left));
      e /= 2;
    }

    // 칸수 n 만큼 채우기
    int diff = len - chs.size();
    if (diff > 0) {
      for (int i = 0; i < diff; i++) {
        chs.push_back("0");
      }
    }

    // 2진수 역순으로 뒤집기
    reverse(chs.begin(), chs.end());

    string str;
    for (auto const &s : chs) {
      str += s;
    }
    ret.push_back(str);
  }

  return ret;
}

vector<string> solution1(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> map1 = to_map(n, arr1);
  vector<string> map2 = to_map(n, arr2);

  vector<string> answer;
  answer.reserve(n);

  for (int i = 0; i < n; i++) {
    string cur = "";
    for (int j = 0; j < n; j++) {
      // 아무나 1이면 #, 아니면 공백.
      if (map1[i][j] == '1' || map2[i][j] == '1') {
        cur += "#";
      } else {
        cur += " ";
      }
    }
    answer.push_back(cur);
  }

  return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> ans;
  ans.reserve(n);

  for (int i = 0; i < n; i++) {
    arr1[i] |= arr2[i];
    string s = "";
    for (int j = 0; j < n; j++) {
      if (arr1[i] % 2 == 0) {
        s = " " + s;
      } else {
        s = "#" + s;
      }
      arr1[i] >>= 1;
    }
    ans.push_back(s);
  }

  return ans;
}