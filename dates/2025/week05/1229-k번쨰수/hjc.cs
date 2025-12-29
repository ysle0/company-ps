public class Program
{
    static int[] solution(int[] array, int[,] commands)
    {
        int   commandCount = commands.GetLength(0);
        int[] answer       = new int[commandCount];
        
        for (int idx = 0; idx < commandCount; idx++)
        {
            int i = commands[idx, 0] - 1;
            int j = commands[idx, 1];
            int k = commands[idx, 2] - 1;

            int[] newArray = new int[j - i];
            for (int l = 0; l < newArray.Length; l++)
            {
                newArray[l] = array[i + l];
            }
            
            Array.Sort(newArray);

            answer[idx] = newArray[k];
        }
        
        return answer;
    }
}