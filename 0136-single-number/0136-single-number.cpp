class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for(auto element : nums) {
            out^=element; //XOR operation을 반복 -> 같은 숫자가 2회 들어올 시, 0이됨
        }
        return out;        
    }
};