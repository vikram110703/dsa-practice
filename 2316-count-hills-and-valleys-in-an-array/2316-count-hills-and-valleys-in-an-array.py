class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        count=0
        left=-1
        right=-1
        i=1
        while(i<len(nums)-1):
            while(i<len(nums) and nums[i-1]==nums[i]):
                i+=1
            left=nums[i-1]

            if(i==len(nums)):
                break

            while(i+1<len(nums) and nums[i]==nums[i+1]):
                i+=1
            if(i+1==len(nums)):
                break
            right=nums[i+1]
            
            for j in range(i+1,len(nums)):
                if(nums[i]!=nums[j]):
                    right=nums[j]
                    break
    
            if(left!=-1 and right!=-1):
                if((left>nums[i] and right>nums[i])or(left<nums[i] and right<nums[i])):
                    count+=1

            i+=1

        return count
        