class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output(2);
        int beg = 0;
        int end = numbers.size()-1;
        int sumup;
        while(beg < end) {
            sumup = numbers[beg]+numbers[end];
            if(sumup == target) {
                output[0] = beg+1;
                output[1] = end+1;
                return output;
            }

            if(sumup < target) {
                if (numbers[beg] == numbers[beg+1]) {
                    while(numbers[beg] == numbers[beg+1]) {
                        beg += 1;
                    }
                }
                else {
                    beg += 1;
                }
            }
            else {
                if (numbers[end] == numbers[end-1]) {
                    while(numbers[end] == numbers[end-1]) {
                        end -= 1;
                    }
                }
                else {
                    end -= 1;
                }

            }

        }
    
        return output;
    }
};