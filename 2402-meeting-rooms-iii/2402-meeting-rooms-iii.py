class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        count_meetings = [0]*n
        store_end_time = [0]*n

        
        for meeting in meetings:
            start_time = meeting[0]
            end_time = meeting[1]
            duration = end_time - start_time
            earliest_end_time = float("inf")
            room_no = -1
            found = False
            for room in range(n):
                if store_end_time[room] <= start_time:
                    store_end_time[room] = end_time
                    count_meetings[room]+=1
                    found = True
                    break
                if store_end_time[room] < earliest_end_time:
                    earliest_end_time = store_end_time[room]
                    room_no = room

            if not found:
                store_end_time[room_no]+=duration
                count_meetings[room_no]+=1

        most_meetings = float('-inf')
        ans = -1
        for i,count in enumerate(count_meetings):
            if most_meetings < count:
                most_meetings = count
                ans  = i
        return ans




            


        