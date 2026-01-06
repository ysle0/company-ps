#include <cmath>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  queue<int> elapsed;
  for (int i = 0; i < progresses.size(); i++) {
    const int left = 100 - progresses[i];
    const int days = ceil((float)left / speeds[i]);
    elapsed.push(days);
  }

  vector<pair<int, int>> v{{elapsed.front(), 1}};
  elapsed.pop();
  int cursor = 0;

  while (!elapsed.empty()) {
    int cur = elapsed.front();
    int last = v[cursor].first;
    if (last >= cur) {
      v[cursor].second++;
    } else {
      last = cur;
      v.push_back({last, 1});
      cursor++;
    }
    elapsed.pop();
  }

  vector<int> ans;
  for (auto [day, cnt] : v) {
    ans.push_back(cnt);
  }
  return ans;
}