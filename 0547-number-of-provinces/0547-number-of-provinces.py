class Solution:
    def bfs(self, node, vis, adjList):
        vis[node] = 1
        q = deque()
        q.append(node)

        while len(q) != 0:
            curr_node = q[0]
            q.popleft()

            for neighbour in adjList[curr_node]:
                if not vis[neighbour]:
                    vis[neighbour] = 1
                    q.append(neighbour)

        return

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        adjList = [[] for i in range(n)]

        for i in range(n):
            for j in range(n):
                if i == j or isConnected[i][j] == 0:
                    continue
                else:
                    adjList[i].append(j)
                    

        vis = [0] * n
        count = 0
        for i in range(0, n):
            if not vis[i]:
                self.bfs(i, vis, adjList)
                count += 1

        return count
