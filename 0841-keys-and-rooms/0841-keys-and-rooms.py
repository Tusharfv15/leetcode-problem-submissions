class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        adjList = [[] for i in range(n)]

        for i in range(0,n):
            for room in rooms[i]:
                adjList[i].append(room)
                


        q = deque()
        vis =  [0]*n
        vis[0] = 1
        q.append(0)

        while len(q)!=0:
            node = q[0]
            q.popleft()

            

            for neighbour in adjList[node]:
                if not vis[neighbour]:
                    vis[neighbour] = 1
                    q.append(neighbour)

        for i in range(n):
            if vis[i] == 0:
                return False

        return True


        
        
