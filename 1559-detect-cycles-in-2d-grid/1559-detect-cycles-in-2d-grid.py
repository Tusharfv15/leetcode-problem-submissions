class Solution:
    def dfs(self,i,j,par_i,par_j,grid,vis):
        vis[i][j] = 1
        n = len(grid)
        m = len(grid[0])
        directions = ((1,0),(0,1),(-1,0),(0,-1))
        for dx,dy in directions:
            ni = i + dx
            nc = j + dy
            if ni >= 0 and ni < n and nc >=0 and nc < m and grid[i][j] == grid[ni][nc]:
                if not vis[ni][nc]:
                    if self.dfs(ni,nc,i,j,grid,vis):
                        return True

                elif (par_i,par_j) != (ni,nc):
                    return True

        return False

    def containsCycle(self, grid: List[List[str]]) -> bool:
        n = len(grid)
        m = len(grid[0])

        vis = [[0]*m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if not vis[i][j] and self.dfs(i,j,-1,-1,grid,vis):
                    return True


        return False
        