class Solution {
private:
    vector<vector<int>> adj_tab;  ////< @note 当前课程idx的直接后置课程为adj_tab[idx]
    vector<int> indegree;         ////< @note 课程idx的入度为indegree[idx]
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj_tab.resize(numCourses);
        indegree.resize(numCourses);

        for (const auto &info : prerequisites) {  ////< @note info[0]-当前课程 info[1]-前置课程
            adj_tab[info[1]].push_back(info[0]);
            ++indegree[info[0]];
        }

        queue<int> q;               ////< @note 入度为0(没有前置课程)的课程入队
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {        ////< @note 每次出队都表示多一门可以学习的课程
            int idx = q.front();
            q.pop();
            res.push_back(idx);
            for (auto next_course : adj_tab[idx]) {
                --indegree[next_course];              ////< @note 当前课程idx的后置课程的入度可以减1
                if (indegree[next_course] == 0) {     ////< @note 若入度减到0，则表示前置课程已学习完，可以入队
                    q.push(next_course);
                }
            }
        }

        if (res.size() != numCourses) {
            return {};
        }
        return res;
    }
};