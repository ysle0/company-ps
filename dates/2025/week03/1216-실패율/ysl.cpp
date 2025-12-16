#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
  map<int, int> stuck;
  // 시간 복잡도: O(N)
  // 공간 복잡도: O(N)
  for (int stage : stages) {
    if (stuck.find(stage) != stuck.end()) {
      stuck[stage]++;
    } else {
      stuck[stage] = 1;
    }
  }

  int player_count = stages.size();
  // 시간 복잡도: O(N)
  // 공간 복잡도: O(N)
  map<int, long> failures;
  for (int i = 0; i < N; i++) {
    int stage = i + 1;
    int players = stuck[stage];
    if (players == 0 || player_count <= 0) {
      failures[stage] = 0;
      continue;
    }

    // 부동소수점 오차 해결을 위해 있는 힘껏 정수형으로 변환..
    const long fail_rate =
        ((double)players / (double)player_count) * 100'000'000'000;
    failures[stage] = fail_rate;
    player_count -= players;
  }

  // 공간 복잡도: O(N)
  vector<pair<int, long>> sorted(failures.begin(), failures.end());

  // sort 의 시간복잡도: O(N log N)
  sort(sorted.begin(), sorted.end(),
       [](pair<int, long> const &a, pair<int, long> const &b) {
         if (a.second != b.second)
           return a.second > b.second;
         return a.first < b.first;
       });

  vector<int> answer;
  // 공간 복잡도: O(N)
  for (auto [stage, rate] : sorted) {
    answer.push_back(stage);
  }

  // 총 시간 복잡도: O(N + NlogN)
  // 총 공간 복잡도: O(4N) -> O(N)
  return answer;
}