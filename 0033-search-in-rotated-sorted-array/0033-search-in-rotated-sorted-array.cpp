class Solution {
public:
    int search(vector<int>& nums, int target) {

        int srt = 0;
        int end = nums.size()-1;
        int mid;
        while (srt <= end) {
            mid = (srt+end) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[srt]) {
                if (target <= nums[mid] && target >= nums[srt]) {
                    end = mid - 1;
                }

                else {
                    srt = mid + 1;
                }
            }
            else {
                if(target >= nums[mid] && target <= nums[end]) {
                    srt = mid + 1;
                }
                else {
                    end = mid - 1;
                }

            }

        }
        return -1;
    }
};