class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if (prerequisites.empty()) {
            return true;
        }

        int m = 0;
        map<int, vector<int>> myMap;
        for (int i = 0; i < prerequisites.size(); i++) {
            myMap[prerequisites[i][1]].push_back(prerequisites[i][0]);
            for (int j = 0; j < 2; j++) {
                m = max(m, prerequisites[i][j]);
            }
        }

        vector<bool> visited(m, false);        //해당 노드를 방문 했었는가?
        vector<bool> cycleStack(m, false);     //현재 탐색 경로에서 해당 노드를 방문하고 있는가?

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCyclic(i, myMap, visited, cycleStack)) {
                return false; 
            }
        }

        return true; 
    }

    bool isCyclic(int course, map<int, vector<int>>& myMap, vector<bool>& visited, vector<bool>& cycleStack) {
        visited[course] = true;
        cycleStack[course] = true;

        for (int neighbor : myMap[course]) {
            if (!visited[neighbor]) {       //아직 방문 안했었으면 해당 노드 들어가서 다시 Cycle 확인 시작
                if (isCyclic(neighbor, myMap, visited, cycleStack)) {
                    return true; 
                }
            } else if (cycleStack[neighbor]) {  //방문 했었으면 현재 방문 중에 2회 연속 방문하였는가 (Cycle이 있는가)
                return true; 
            }
        }

        cycleStack[course] = false;
        return false;                //아무 사이클이 없음
    }
};
