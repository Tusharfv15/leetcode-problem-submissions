class Solution:

    def check(self,mid,tot_area,squares):
        bot_area = 0

        for square in squares:
            y_low = square[1]
            l = square[2]
            y_high = y_low + l

            if mid > y_high:
                bot_area += l*l

            elif mid > y_low:
                bot_area += l*(mid-y_low)

            
        return bot_area >= tot_area/2.0

            
    def separateSquares(self, squares: List[List[int]]) -> float:
        low = 0
        high = -1
        tot_area = 0
        for square in squares:
            x = square[0]
            y = square[1]
            l = square[2]
            tot_area += l*l
            high =  max(high,y+l)

        ans = -1
        while high - low >= 10**-5:
            mid = high + ((low-high)/2.0)
            ans = mid
            if self.check(mid,tot_area,squares):
                high = mid

            else:
                low = mid
        return ans


