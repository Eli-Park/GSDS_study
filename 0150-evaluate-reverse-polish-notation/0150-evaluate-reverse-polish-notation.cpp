class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int out;
        vector<int> numbers;
        for(auto element : tokens) {
            if (element.compare("+")==0 ) {
                numbers[numbers.size()-2] = numbers[numbers.size()-2] + numbers[numbers.size()-1];
                numbers.pop_back();
            } else if (element.compare("-")==0) {
                numbers[numbers.size()-2] = numbers[numbers.size()-2] - numbers[numbers.size()-1];
                numbers.pop_back();
            } else if (element.compare("*")==0) {
                numbers[numbers.size()-2] = numbers[numbers.size()-2] * numbers[numbers.size()-1];
                numbers.pop_back();
            } else if (element.compare("/")==0) {
                numbers[numbers.size()-2] = numbers[numbers.size()-2] / numbers[numbers.size()-1];
                numbers.pop_back();
            } else {
                numbers.push_back(stoi(element));
            }
        }
        out = numbers[0];
        return out;
    }
};