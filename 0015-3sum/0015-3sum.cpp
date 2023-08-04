class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int s;
        int t;
        vector<int> s_nums = nums;

        sort(s_nums.begin(), s_nums.end());

        int temp_sum;
        int temp_cri;

        for(int i =0 ; i < s_nums.size()-2 ; i++) {
            if(i > 0 && s_nums[i]==s_nums[i-1]) {
                continue;
            }
            s = i + 1;
            t = s_nums.size()-1;

            temp_cri = s_nums[i];
            while(s < t) {
                temp_sum = s_nums[s]+s_nums[t];
                if(temp_sum+temp_cri == 0) {
                    output.push_back({s_nums[i], s_nums[s], s_nums[t]});
                }
                
                if(temp_sum + temp_cri < 0) {
                    while(s < t && s_nums[s]==s_nums[s+1]) {
                        s += 1;
                    }
                    s+=1;
                }
                else {
                    while(s < t && s_nums[t]==s_nums[t-1]) {
                        t -= 1;
                    }
                    t -= 1;
                }   

            }
            
        }



        return output;
        
    }
};