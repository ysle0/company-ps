#include <algorithm>
#include <set>
#include <string>

using namespace std;

set<char> filters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                  'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3',
                  '4', '5', '6', '7', '8', '9', '-', '_', '.'};

string solution(string new_id) {
  // #1
  std::transform(new_id.begin(), new_id.end(), new_id.begin(),
                 [&](char c) { return isupper(c) ? tolower(c) : c; });

  // #2
  auto rm_char = std::remove_if(new_id.begin(), new_id.end(), [&](char c) {
    return filters.find(c) == filters.end();
  });
  new_id.erase(rm_char, new_id.end());

  // #3
  string s;
  for (int i = 0; i < new_id.size(); i++) {
    if (new_id[i] == '.' && !s.empty() && s.back() == '.')
      continue;
    s += new_id[i];
  }
  new_id = s;

  // #4
  if (new_id.front() == '.')
    new_id.erase(0, 1);
  if (new_id.back() == '.')
    new_id.pop_back();

  // #5
  if (new_id.empty())
    new_id = "a";

  // #6
  if (new_id.size() >= 16) {
    new_id = new_id.substr(0, 15);
    if (new_id.back() == '.')
      new_id.pop_back();
  }

  // #7
  while (new_id.size() < 3) {
    new_id += new_id.back();
  }

  return new_id;
}