class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        nums_dict = {}
        max_len = 0
        for item in nums:
            if item not in nums_dict:
                nums_dict[item] = 0
            nums_dict[item] += 1
            if nums_dict[item] > max_len:
                max_len = nums_dict[item]
        sol = [[] for _ in range(max_len)]
        for key in nums_dict:
            for i in range(nums_dict[key]):
                sol[i].append(key)
        return sol
