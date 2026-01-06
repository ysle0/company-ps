#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  stack<int> st;

  for (int i = 0; i < arr.size(); i++) {
    if (st.empty() == false && st.top() == arr[i])
      continue;
    st.push(arr[i]);
  }

  vector<int> ans;
  ans.reserve(st.size());
  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    ans.push_back(cur);
  }

  vector<int> ret(ans.rbegin(), ans.rend());
  return ret;
}