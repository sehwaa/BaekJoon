test_case = int(input())


def bfs(side_num: int, start_y: int, start_x: int, end_y: int, end_x: int) -> int:
    visited = [[0] * side_num for _ in range(side_num)]
    queue = [(start_y, start_x)]
    visited[start_y][start_x] = 1

    co = [(-2, 1), (-1, 2), (1, 2), (2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]

    while len(queue) != 0:
        y, x = queue.pop(0)

        if y is end_y and x is end_x:
            return visited[y][x] - 1

        for cy, cx in co:
            py = y + cy
            px = x + cx
            if 0 <= py < side_num and 0 <= px < side_num and visited[py][px] == 0:
                queue.append((py, px))
                visited[py][px] = visited[y][x] + 1


for case in range(0, test_case):
    side = int(input())
    startY, startX = input().split()
    endY, endX = input().split()
    print(bfs(side, int(startY), int(startX), int(endY), int(endX)))
