class Solution {
public:
    int maxArea(vector<int>& height) {
        int curmax;
        int totmax = 0;
        int min_height;

        int beg = 0;
        int end = height.size()-1;

        while(beg < end) {
                min_height = min(height[beg], height[end]);
                curmax = (end-beg) * min_height;

                totmax = max(totmax, curmax);

                if(height[beg] > height[end]) {
                    end -= 1;
                }
                else {
                    beg += 1;
                }
            
        }
        return totmax;
    }
};