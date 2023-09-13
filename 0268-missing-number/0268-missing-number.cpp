class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int tot = 0;
        for (int i = 0; i < len+1; i++) {
            tot += i;
        }
        for (auto element : nums) {
            tot -= element;
        }
        return tot;        
    }
};