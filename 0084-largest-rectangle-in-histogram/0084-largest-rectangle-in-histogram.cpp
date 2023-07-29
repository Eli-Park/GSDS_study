class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int, int>> s;

        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && s.top().first >= heights[i]) {
                    s.pop();
            }

            if (s.empty()) {
                right[i] = n-1;
            } else {
                right[i] = s.top().second - 1;
            }

            s.push({heights[i], i});
        }

        s = {};

        for(int i = 0; i < n; i++) {
            while(!s.empty() && s.top().first >= heights[i] ) {
                s.pop();
            } 

            if (s.empty()) {
                left[i] = 0;
            } else {
                left[i] = s.top().second + 1;
            }

            s.push({heights[i], i});
        }
        int maximum;
        for (int i = 0; i < n; i++) {
            maximum = max(heights[i] * (right[i]-left[i] + 1), maximum);
        }

        return maximum;
    }

        
    
};