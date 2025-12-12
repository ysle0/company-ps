#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

map<char, pair<int, int>> keymaps;

vector<int> solution(vector<string> keymap, vector<string> targets) {
  vector<int> answer(targets.size(), 0);

  for (int i = 0; i < keymap.size(); i++) {
    for (int j = 0; j < keymap[i].size(); j++) {
      if (keymaps.find(keymap[i][j]) == keymaps.end()) {
        keymaps[keymap[i][j]] = make_pair(i, j + 1);
      } else {
        keymaps[keymap[i][j]] =
            make_pair(i, min(keymaps[keymap[i][j]].second, j + 1));
      }
    }
  }

  for (int i = 0; i < targets.size(); i++) {
    for (char c : targets[i]) {
      if (keymaps.find(c) == keymaps.end()) {
        answer[i] = -1;
        break;
      }

      answer[i] += keymaps[c].second;
    }
  }

  return answer;
}