#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto const& cmd: commands) {
        const int from = cmd[0]-1;
        const int to = cmd[1];
        const int select = cmd[2]-1;
        vector<int> slice(array.begin() + from, array.begin() + to);
        sort(slice.begin(), slice.end());
        answer.push_back(slice[select]);
    }
    return answer;
}
