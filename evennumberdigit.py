<<<<<<< HEAD
class Solution:
    def findEvenDigit(self,nums):
        evendigitcnt=0
        while nums!= 0:
            nums=nums//10
            evendigitcnt+=1
        return evendigitcnt % 2 ==0    
    def findNumbers(self, nums: list[int]) -> int:
        evencnt=0
        for i in range(len(nums)):
            if self.findEvenDigit(nums[i]):
                evencnt+=1
        return evencnt
obj=Solution()
list1=eval(input("take input from the user:"))
print(obj.findNumbers(12,234,4567,23,3))
=======
class Solution:
    def findEvenDigit(self,nums):
        evendigitcnt=0
        while nums!= 0:
            nums=nums//10
            evendigitcnt+=1
        return evendigitcnt % 2 ==0    
    def findNumbers(self, nums: list[int]) -> int:
        evencnt=0
        for i in range(len(nums)):
            if self.findEvenDigit(nums[i]):
                evencnt+=1
        return evencnt
obj=Solution()
list1=eval(input("take input from the user:"))
print(obj.findNumbers(12,234,4567,23,3))
>>>>>>> 9777ce9275c4f8345e3c897d7d500b9f70545c62
