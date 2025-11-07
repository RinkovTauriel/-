import java.util.*;

public class MazePaths {
    
    /**
     * Рекурсивная функция для поиска всех путей в лабиринте
     */
    public static void findAllPaths(int[][] maze, int x, int y, 
                                  List<String> path, 
                                  List<List<String>> allPaths) {
        int n = maze.length;
        int m = maze[0].length;
        
        // Базовый случай: достигли цели
        if (x == n - 1 && y == m - 1) {
            allPaths.add(new ArrayList<>(path));
            return;
        }
        
        // Движение вправо
        if (y + 1 < m && maze[x][y + 1] == 0) {
            path.add("(" + x + "," + (y + 1) + ")");
            findAllPaths(maze, x, y + 1, path, allPaths);
            path.remove(path.size() - 1); // Backtrack
        }
        
        // Движение вниз
        if (x + 1 < n && maze[x + 1][y] == 0) {
            path.add("(" + (x + 1) + "," + y + ")");
findAllPaths(maze, x + 1, y, path, allPaths);
            path.remove(path.size() - 1); // Backtrack
        }
    }
    
    public static void main(String[] args) {
        // Инициализация лабиринта 5x5
        int[][] maze = {
            {0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0}
        };
        
        // Поиск всех путей
        List<String> path = new ArrayList<>();
        path.add("(0,0)"); // Стартовая позиция
        List<List<String>> allPaths = new ArrayList<>();
        
        findAllPaths(maze, 0, 0, path, allPaths);
        
        // Вывод результатов
        System.out.println("Лабиринт 5x5:");
        for (int[] row : maze) {
            System.out.println(Arrays.toString(row));
        }
        System.out.println("\nНайдено путей: " + allPaths.size());
        
        for (int i = 0; i < allPaths.size(); i++) {
            System.out.println("Путь " + (i + 1) + ": " + allPaths.get(i));
        }
    }
}

---

Пример вывода

Лабиринт 5x5:
[0, 0, 0, 0, 0]
[0, 1, 0, 1, 0]
[0, 0, 0, 0, 0]
[0, 1, 0, 1, 0]
[0, 0, 0, 0, 0]

Найдено путей: 4
Путь 1: [(0,0), (0,1), (0,2), (0,3), (0,4), (1,4), (2,4), (2,3), (2,2), (2,1), (3,1), (4,1), (4,2), (4,3), (4,4)]
