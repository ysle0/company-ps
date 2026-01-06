#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  const size_t select = nums.size() / 2;
  return min(select, s.size());
}