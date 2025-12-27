import heapq
from typing import List

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()

        available_rooms = list(range(n))
        heapq.heapify(available_rooms)

        used_rooms = []
        usedCount = [0] * n

        for start, end in meetings:
            duration = end - start

            while used_rooms and used_rooms[0][0] <= start:
                endTime, room = heapq.heappop(used_rooms)
                heapq.heappush(available_rooms, room)

            if available_rooms:
                room = heapq.heappop(available_rooms)
                heapq.heappush(used_rooms, (end, room))
                usedCount[room] += 1
            else:
                endTime, room = heapq.heappop(used_rooms)
                heapq.heappush(used_rooms, (endTime + duration, room))
                usedCount[room] += 1

        ans = 0
        for i in range(n):
            if usedCount[i] > usedCount[ans]:
                ans = i

        return ans
