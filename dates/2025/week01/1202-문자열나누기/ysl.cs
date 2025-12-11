public class Solution
{
  public int solution(string s)
  {
    int answer = 0;
    while (s.Length > 0)
    {
      char x = s[0];
      int match = 0;
      int unmatch = 0;
      int splitPos = 0;
      int cursor = 0;
      bool hadMatch = false;

      while (cursor < s.Length)
      {
        char current = s[cursor];
        if (x == current)
        {
          match++;
        }
        else
        {
          unmatch++;
        }

        if (match == unmatch)
        {
          hadMatch = true;
          splitPos = cursor;
          break;
        }

        cursor++;
      }

      if (!hadMatch)
        return answer + 1;

      s = s.Substring(splitPos + 1);
      answer++;
    }

    return answer;
  }
}