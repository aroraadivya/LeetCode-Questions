class Solution(object):
    def hasValidPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        connects = {
            1: {0, 1},
            2: {2, 3},
            3: {0, 3},
            4: {1, 3},
            5: {0, 2},
            6: {1, 2},
        }
        dr = [0, 0, -1, 1]
        dc = [-1, 1, 0, 0]
        opp = [1, 0, 3, 2]
        
        visited = [[False]*n for _ in range(m)]
        queue = [(0, 0)]
        visited[0][0] = True
        
        while queue:
            r, c = queue.pop(0)
            if r == m-1 and c == n-1:
                return True
            for d in range(4):
                nr, nc = r + dr[d], c + dc[d]
                if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                    if d in connects[grid[r][c]] and opp[d] in connects[grid[nr][nc]]:
                        visited[nr][nc] = True
                        queue.append((nr, nc))
        return False