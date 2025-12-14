
public class Program
{
    // 시간 복잡도 O(n)
    // 공간 복잡도 O(1)
    static int[] solution(string[] keymap, string[] targets)
    {
        int[] answer = new int[targets.Length];

        Dictionary<char, int> keymapDictionary = new Dictionary<char, int>();
        for (int i = 0; i < keymap.Length; i++)
        {
            for (int j = 0; j < keymap[i].Length; j++)
            {
                bool isKey = keymapDictionary.TryGetValue(keymap[i][j], out int keyOrder);

                if (isKey)
                {
                    if (keyOrder > j)
                    {
                        keymapDictionary[keymap[i][j]] = j + 1;
                    }
                }
                else
                {
                    keymapDictionary.Add(keymap[i][j], j + 1);
                }
            }
        }

        for (int i = 0; i < targets.Length; i++)
        {
            for (int j = 0; j < targets[i].Length; j++)
            {
                bool isKey = keymapDictionary.TryGetValue(targets[i][j], out int keyOrder);

                if (isKey)
                {
                    answer[i] += keyOrder;
                }
                else
                {
                    answer[i] = -1;
                    break;
                }
            }
        }
        
        return answer;
    }
}