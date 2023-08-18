class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        output = [[]]

        for element in nums :
            output += [res + [element] for res in output]
        return output
    


