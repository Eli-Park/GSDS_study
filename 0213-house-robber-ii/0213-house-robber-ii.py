class Solution(object):
    def _rob_helper(self, nums) :
        r1 = r2 = 0
        for element in nums :                  #r2 (현재와 -2 index 차이)에 현재 값 더해줌
            r1, r2 = r2 + element, max(r1, r2) #현재까지의 값 중, -1과 -2 위치 중 더 큰 값 받아옴
        return max(r1, r2)

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_len = len(nums)

        r1 = 0
        r2 = 0
        r3 = 0

        if max_len <= 3 :
            try :
                r1 = nums[0]
                r2 = nums[1]
                r3 = nums[2]
            except : 
                None
            return max(r1, r2, r3)
        
        else :
            return max(self._rob_helper(nums[1:]), self._rob_helper(nums[:-1]))