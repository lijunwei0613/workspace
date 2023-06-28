import sys 
class Solution:
    def findRepeatNumber(self, nums: list[int]) -> int:
        i = 0
        # nums=[1,2,3,5,4,2] 
        if nums == None:
            return -1
        
        while i < len(nums):
              
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]: return nums[i]
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        print ("11111111111") 
        return -1

# 暴力循环
# class Solution:
#     def findRepeatNumber(self, nums: list[int]) -> int:
#         nums=[1,2,3,5,4,2] 
#         nums.sort()
#         n = len(nums)
#         for i in range(n - 1):
#             if nums[i] == nums[i + 1]: 
#                 print(nums[i])
#                 return nums[i]  
#         return []

        

    # def findRepeatNumber(self, nums: list[int]) -> int:
    #     dic = set()
    #     for num in nums:
    #         if num in dic: return num
    #         dic.add(num)
    #         print(num)
    #     return -1