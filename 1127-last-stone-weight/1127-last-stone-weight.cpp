class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int temp_sub;

        sort(stones.rbegin(), stones.rend()); //내림차순 정렬

        while(stones.size()>=2) {
            temp_sub = stones[0]-stones[1]; //가장 큰 2개의 차 구함
            if (temp_sub == 0) { //가장 큰 2개 삭제
                stones.erase(stones.begin());
                stones.erase(stones.begin());
                continue; //정렬 또 할 필요 없으므로 다음 loop
            }
            else {
                stones.erase(stones.begin());
                stones.erase(stones.begin());
                stones.push_back(temp_sub);
                sort(stones.rbegin(), stones.rend()); //내림차순 재정렬                
            }           
        }

        if (stones.size() == 0) {
            return 0;
        }
        else {
            return stones[0];
        }

    }
};