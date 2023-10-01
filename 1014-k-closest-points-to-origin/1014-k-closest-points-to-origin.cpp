class Solution {
public:
    static auto comp(const pair<int, vector<int>>& a,  const pair<int, vector<int>>& b) { //pair의 첫 자리로 비교하는 함수
        if (a.first != b.first)
            return (a.first < b.first);
        else
            return (a.second > b.second);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int dist;
        vector<pair<int, vector<int>>> dist_points;
        vector<vector<int>> output;

        for (auto element : points) {
            dist = pow(element[0], 2) + pow(element[1], 2); //어차피 제곱만 비교하면 됨
            pair<int, vector<int>> temp_pair(dist, element);
            dist_points.push_back(temp_pair); // pair<distance, vectors> push back!
        }

        sort(dist_points.begin(), dist_points.end(), comp);

        for (int i = 0; i < k; i++) {
            output.push_back(dist_points[i].second);
        }
        return output;
    }
};
