#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
  unordered_map<char, int> keymaps;
  vector<int> answer(targets.size(), 0);

  for (int i = 0; i < keymap.size(); i++) {
    for (int j = 0; j < keymap[i].size(); j++) {
      if (keymaps.find(keymap[i][j]) == keymaps.end()) {
        keymaps[keymap[i][j]] = j + 1;
      } else {
        keymaps[keymap[i][j]] = min(keymaps[keymap[i][j]], j + 1);
      }
    }
  }

  for (int i = 0; i < targets.size(); i++) {
    for (char c : targets[i]) {
      if (keymaps.find(c) == keymaps.end()) {
        answer[i] = -1;
        break;
      }

      answer[i] += keymaps[c];
    }
  }

  return answer;
}