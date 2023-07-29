class Solution {
public:
/*
The idea here is to maintain a stack of decreasing order. If the incoming element is greater than the top of the stack, we pop from the stack and add the new element.

*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> ans(temperatures.size(), 0);
      stack<pair<int, int>> s;
      
      for (int i = 0; i < temperatures.size(); i++){
          auto temp = temperatures[i];
          while(!s.empty() && temp > s.top().first){
              auto toPop = s.top();
              s.pop();
              ans[toPop.second] = i - toPop.second;
          }
          if(s.empty() || temp <= s.top().first){
              s.push({temp, i});
          }
      }
      return ans;
    }
};