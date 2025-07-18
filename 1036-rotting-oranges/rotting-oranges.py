class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        queue = deque()
        fresh = 0

        # Step 1: Initialize queue with all rotten oranges and count fresh ones
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c, 0))  # (row, col, time)
                elif grid[r][c] == 1:
                    fresh += 1

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right
        time_elapsed = 0

        # Step 2: BFS
        while queue:
            r, c, time = queue.popleft()
            time_elapsed = max(time_elapsed, time)

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                # Check boundaries and if it's a fresh orange
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                    grid[nr][nc] = 2  # Mark as rotten
                    fresh -= 1
                    queue.append((nr, nc, time + 1))

        return time_elapsed if fresh == 0 else -1
