#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> dict;

for (int num : nums) {
    dict.try_emplace(num, 0);
}

return min(static_cast<int>(dict.size()), static_cast<int>(nums.size()) / 2);
}
