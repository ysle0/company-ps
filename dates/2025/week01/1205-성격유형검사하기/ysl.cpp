#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> m{
    {'A', 0}, {'N', 0}, {'J', 0}, {'M', 0},
    {'C', 0}, {'F', 0}, {'R', 0}, {'T', 0},
};

void evaluate(char c1, char c2, string &answer) {
  if (m[c1] > m[c2]) {
    answer += c1;
  } else if (m[c1] < m[c2]) {
    answer += c2;
  } else {
    answer += c1 - c2 < 0 ? c1 : c2;
  }
}

string solution(vector<string> survey, vector<int> choices) {
  for (int i = 0; i < survey.size(); i++) {
    const int score = choices[i] - 4;
    if (score < 0) {
      m[survey[i][0]] += -score;
    } else {
      m[survey[i][1]] += score;
    }
  }

  string answer = "";
  evaluate('R', 'T', answer);
  evaluate('C', 'F', answer);
  evaluate('J', 'M', answer);
  evaluate('A', 'N', answer);

  return answer;
}