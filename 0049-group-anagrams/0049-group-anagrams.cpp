class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> ordered_chars;
        
        for(std::string element : strs) {
            std::string ordered = element;
            std::sort(ordered.begin(), ordered.end());
            ordered_chars[ordered].push_back(element);
        }

        for(auto out : ordered_chars) {
            output.push_back(out.second);
        }

        return output;
    }
};