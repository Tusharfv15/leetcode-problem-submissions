class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        ans = []
        for i in range (len(code)):
            if not isActive[i]:
                continue
            if businessLine[i] not in ["electronics", "grocery", "pharmacy", "restaurant"]:
                continue
            if len(code[i]) == 0:
                continue
            is_valid = True
            for c in code[i]:
                if not c.isalnum() and c != "_":
                    is_valid = False
                    break
            if not is_valid:
                continue
            ans.append(i)
        order = {
            "electronics": 0,
            "grocery": 1,
            "pharmacy": 2,
            "restaurant": 3
        }
        ans.sort(key = lambda x : (order[businessLine[x]],code[x]))
        return [code[i] for i in ans]
                