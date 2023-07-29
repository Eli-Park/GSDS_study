class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;

        recursion(0, 0, n, "", output);
        return output;

    }
    void recursion(int left, int right, int n, string cur, vector<string>& final) {
        if (cur.length() == 2*n) {
            final.push_back(cur);
            return;
        }

        if (left < n) {
            recursion(left + 1, right, n, cur + "(", final);
        }

        if (right < left) {
            recursion(left, right + 1, n, cur + ")", final);
        }
    }
};