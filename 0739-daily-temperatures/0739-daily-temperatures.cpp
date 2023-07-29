class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size(), 0);
        stack<pair<int,int>> s;

        for (int i = 0; i < temperatures.size(); i++) {
            int cur = temperatures[i];

            while(!s.empty() && cur > s.top().first) {
                auto compar = s.top();
                s.pop();
                output[compar.second] = i - compar.second;
            }

            if(s.empty() || cur <= s.top().first) {
                s.push({cur, i});
            }


        }
        return output;

        
    }
};