class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        out = [nums[0]]

        for num_ind in range(1, len(nums)) :
            if out[-1] < nums[num_ind] :
                out.append(nums[num_ind])
            else :
                start = 0
                end = len(out) - 1

                while start < end :
                    mid = (start + end) // 2
                    if nums[num_ind] > out[mid] :
                        start = mid + 1
                    else :
                        end = mid

                out[start] = nums[num_ind]
        
        return len(out)




