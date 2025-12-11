#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
  vector<int> answer;
  vector<int> hof;
  hof.reserve(k);

  for (int i = 0; i < min(k, (int)score.size()); i++) {
    hof.push_back(score[i]);
    std::sort(hof.rbegin(), hof.rend());
    answer.push_back(hof[hof.size() - 1]);
  }

  for (int i = k; i < score.size(); i++) {
    int min = hof[hof.size() - 1];
    if (score[i] > min) {
      hof[hof.size() - 1] = score[i];
      std::sort(hof.rbegin(), hof.rend());
      min = hof[hof.size() - 1];
    }

    answer.push_back(min);
  }

  return answer;
}