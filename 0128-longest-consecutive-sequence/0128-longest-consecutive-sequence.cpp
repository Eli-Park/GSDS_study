class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int pri = nums[0];
        int cons = 1;
        int max_cons = 1;
        for(int i = 1; i < nums.size() ; i++) {
            int cur = nums[i] ;
            if(cur - pri == 1) {
                cons += 1;
                if (max_cons < cons) {
                    max_cons = cons;
                }
            }
            else if (cur - pri > 1) {
                cons = 1;
            }
            pri = cur;
        }
        return max_cons;        
    }
};