# 1218-폰켓몬 풀이

## **문제 정보**

- **문제 링크**: https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=cpp
- **난이도**: 1
- **문제 분류**: 해시
- **사용 언어**: c++
- **걸린 시간**: 30분
- **도움 찾아본 시간**:

## **풀이 설명**

전체 폰켓몬들 중 반절을 고를 때 최대로 다양하게 고를 수 있는 수를 구하기.

1. map에 nums를 키로 담기
2. map의 크기와 nums.size / 2 중 더 작은 것을 반환

```jsx
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
```

## **시간/공간 복잡도**

- 시간 복잡도: O(n)
- 공간 복잡도: O(n)

## **몰랐던 점 / 배운 점**

- unordered_set 으로 배열의 처음부터 끝까지 간단하게 담을 수 있다

```jsx
unordered_set<int> set(nums.begin(), nums.end());
```

- c++에서는 size()가 size_t를 반환하므로 int로 캐스팅 필요