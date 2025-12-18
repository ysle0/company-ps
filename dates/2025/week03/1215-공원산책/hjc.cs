public class Program
{
    // 시간 복잡도 : park 크기와 routes 크기에 선형적으로 비례하므로 O(n)
    // 공간 복잡도 : O(1)
    
    static int[] solution(string[] park, string[] routes)
    {
        int[] answer = new int[2];

        (int x, int y) startPoint = (0, 0);
        bool foundStartPoint = false;
        // 시작 위치 찾기
        for (int i = 0; i < park.Length; i++)
        {
            for (int j = 0; j < park[i].Length; j++)
            {
                if (park[i][j] == 'S')
                {
                    startPoint = (i, j);
                    foundStartPoint = true;
                    break;
                }
            }

            if (foundStartPoint)
            {
                break;
            }
        }
        
        var dir = new Dictionary<string, (int dx, int dy)>
        {
            {"E", (0, 1)}, {"W", (0, -1)},
            {"S", (1, 0)}, {"N", (-1, 0)}
        };

        foreach (string route in routes)
        {
            string[] parts = route.Split(' ');
            string direction = parts[0];
            int distance = int.Parse(parts[1]);
            
            var (dx, dy) = dir[direction];
            bool canMove = true;

            for (int step = 1; step <= distance; step++)
            {
                int nx = startPoint.x + dx * step;
                int ny = startPoint.y + dy * step;

                if (nx < 0 || nx >= park.Length ||
                    ny < 0 || ny >= park[0].Length ||
                    park[nx][ny] == 'X')
                {
                    canMove = false;
                    break;
                }
            }

            if (canMove)
            {
                startPoint.x += dx * distance;
                startPoint.y += dy * distance;
            }
        }
        
        answer[0] = startPoint.x;
        answer[1] = startPoint.y;

        ;
        return answer;
    }
}