def find_all_paths(maze, x, y, path, all_paths):
    """
    Рекурсивная функция для поиска всех путей в лабиринте
    
    Args:
        maze: двумерный массив лабиринта
        x, y: текущие координаты
        path: текущий путь
        all_paths: список всех найденных путей
    """
    n = len(maze)
    m = len(maze[0])
    
    # Базовый случай: достигли цели
    if x == n - 1 and y == m - 1:
        all_paths.append(path[:])  # Сохраняем копию пути
        return
    
    # Движение вправо
    if y + 1 < m and maze[x][y + 1] == 0:
        path.append((x, y + 1))
        find_all_paths(maze, x, y + 1, path, all_paths)
        path.pop()  # Backtrack
    
    # Движение вниз
    if x + 1 < n and maze[x + 1][y] == 0:
        path.append((x + 1, y))
        find_all_paths(maze, x + 1, y, path, all_paths)
        path.pop()  # Backtrack

def main():
    # Инициализация лабиринта 5x5
    maze = [
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    
    # Поиск всех путей
    start = (0, 0)
    all_paths = []
    path = [start]  # Начинаем со стартовой позиции
    
    find_all_paths(maze, 0, 0, path, all_paths)
    
    # Вывод результатов
    print(f"Лабиринт 5x5:")
    for row in maze:
        print(row)
    print(f"\nНайдено путей: {len(all_paths)}")
    
    for i, p in enumerate(all_paths, 1):
        print(f"Путь {i}: {p}")

if __name__ == "__main__":
    main()
