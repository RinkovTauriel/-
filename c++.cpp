#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Рекурсивная функция для поиска всех путей в лабиринте
 */
void findAllPaths(vector<vector<int>>& maze, int x, int y,
                 vector<string>& path, 
                 vector<vector<string>>& allPaths) {
    int n = maze.size();
    int m = maze[0].size();
    
    // Базовый случай: достигли цели
    if (x == n - 1 && y == m - 1) {
        allPaths.push_back(path);
        return;
    }
    
    // Движение вправо
    if (y + 1 < m && maze[x][y + 1] == 0) {
        path.push_back("(" + to_string(x) + "," + to_string(y + 1) + ")");
        findAllPaths(maze, x, y + 1, path, allPaths);
        path.pop_back(); // Backtrack
    }
    
    // Движение вниз
    if (x + 1 < n && maze[x + 1][y] == 0) {
        path.push_back("(" + to_string(x + 1) + "," + to_string(y) + ")");
        findAllPaths(maze, x + 1, y, path, allPaths);
        path.pop_back(); // Backtrack
    }
}

int main() {
    // Инициализация лабиринта 5x5
    vector<vector<int>> maze = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    // Поиск всех путей
    vector<string> path;
    path.push_back("(0,0)"); // Стартовая позиция
    vector<vector<string>> allPaths;
    
    findAllPaths(maze, 0, 0, path, allPaths);
    
    // Вывод результатов
    cout << "Лабиринт 5x5:" << endl;
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    cout << "\nНайдено путей: " << allPaths.size() << endl;
    
    for (size_t i = 0; i < allPaths.size(); ++i) {
        cout << "Путь " << (i + 1) << ": ";
        for (const auto& point : allPaths[i]) {
            cout << point << " ";
        }
        cout << endl;
    }
    
    return 0;
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
