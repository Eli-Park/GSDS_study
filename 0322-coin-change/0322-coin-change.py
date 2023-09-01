class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        memo = {}  # Use a dictionary for memoization
        result = self._cHelper(coins, amount, memo)
        return result if result != sys.maxsize else -1
        
    def _cHelper(self, coins, lamount, memo):
        if lamount == 0 :
            return 0

        if lamount in memo:
            return memo[lamount]

        min_coins = sys.maxsize
        for coin in coins:
            if lamount - coin >= 0:
                sub_result = self._cHelper(coins, lamount - coin, memo)
                if sub_result != sys.maxsize:
                    min_coins = min(min_coins, sub_result + 1)
        
        memo[lamount] = min_coins
        return min_coins
