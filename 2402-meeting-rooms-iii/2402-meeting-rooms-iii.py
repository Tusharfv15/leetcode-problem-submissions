import heapq
from typing import List

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # sort meetings by start time
        meetings.sort()

        # min-heap of available rooms
        available_rooms = list(range(n))
        heapq.heapify(available_rooms)

        # min-heap of (endTime, room)
        used_rooms = []

        usedCount = [0] * n

        for start, end in meetings:
            duration = end - start

            # free rooms that have finished before current meeting starts
            while used_rooms and used_rooms[0][0] <= start:
                endTime, room = heapq.heappop(used_rooms)
                heapq.heappush(available_rooms, room)

            if available_rooms:
                # assign smallest available room
                room = heapq.heappop(available_rooms)
                heapq.heappush(used_rooms, (end, room))
                usedCount[room] += 1
            else:
                # delay meeting, reuse earliest finishing room
                endTime, room = heapq.heappop(used_rooms)
                heapq.heappush(used_rooms, (endTime + duration, room))
                usedCount[room] += 1

        # find room with maximum usage (smallest index if tie)
        ans = 0
        for i in range(n):
            if usedCount[i] > usedCount[ans]:
                ans = i

        return ans
