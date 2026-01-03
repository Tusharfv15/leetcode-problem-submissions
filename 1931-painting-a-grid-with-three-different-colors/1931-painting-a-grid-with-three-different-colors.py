class Solution:
    mod = 10**9 + 7
    def f(self,n,state,ind,states,mem):

        if n == 0:
            return 1

        key = f"{n}_{state}"
        if key in mem:
            return mem[key]
    
        ans = 0
        for next_state in states:
            conflict = 0
            for ch1,ch2 in zip(next_state,state):
                if ch1 == ch2:
                    conflict = 1
                    break
            if not conflict:
                ans = (ans + self.f(n-1,next_state,ind,states,mem))%self.mod
        mem[key] = ans
        return mem[key]
                    
    def buildState(self,states,colors,ind,curr,m):
        if ind == m:
            states.append("".join(curr))
            return

        for color in colors:
            if ind == 0 or curr[-1] != color:
                curr.append(color)
                self.buildState(states,colors,ind+1,curr,m)
                curr.pop()


    def colorTheGrid(self, m: int, n: int) -> int:
        colors = ['R','G','B']
        states = []
        
        self.buildState(states,colors,0,[],m)
        ans = 0
        mem = {}
        for ind,state in enumerate(states):
            ans =  (ans + self.f(n-1,state,ind,states,mem))%self.mod


        return ans

