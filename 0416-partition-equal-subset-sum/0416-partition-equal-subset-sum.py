class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ts = sum(nums)
        if ts % 2 == 1 :    #Total Sum이 홀수인 경우, 정수로는 2개의 Subset 형성 불가능 (각 Subset의 합이 동일하므로)
            return False
        else : 
            dp = [True] + [False]*(ts//2) # 0번째는 아무 Element 사용하지 않는 경우, 무조건 True
                                          # 반절의 합을 구할 수 있으면, 나머지 반절은 자동으로 OK

            for num in nums :                            #전체 List에 대하여 Loop
                for curr in range(ts//2, num-1, -1) :    #각 값에서 num을 차감한 숫자가 이전 Iter에서 True로 매핑 된 경우
                                                         #num을 추가한 현재의 경우에도 True가 됨
                    dp[curr] = dp[curr] or dp[curr-num]

        return dp[-1]                      #최종적으로, dp[-1]이 True인 경우, 전체 조건을 만족한다고 볼 수 있음