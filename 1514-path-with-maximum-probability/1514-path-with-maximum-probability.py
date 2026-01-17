import heapq

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        dist = [0]*n
        adjList = defaultdict(list)
        ind = 0
        for edge in edges:
            adjList[edge[0]].append((edge[1],succProb[ind]))
            adjList[edge[1]].append((edge[0],succProb[ind]))
            ind+=1

        pq = [(-1,start_node)]
        while pq:
            d,node = heapq.heappop(pq)
            d = -d
            for neighbour,distance in adjList[node]:
                if distance*d > dist[neighbour]:
                    dist[neighbour] = distance*d
                    heapq.heappush(pq,(-dist[neighbour],neighbour))

        
        return dist[end_node]