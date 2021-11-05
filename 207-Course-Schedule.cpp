/**
 *There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
作者：li-kou-it
链接：https://leetcode-cn.com/problems/course-schedule/solution/bfsban-ben-tuo-bu-pai-xu-c-by-li-kou-it-pytj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Graph
        {
        private:
            vector<vector<int> > adj;
            vector<int> Indegree;
        public:
            Graph(int numCourses, vector<vector<int>>& prerequisites)
            {
                adj.resize(numCourses);
                Indegree.assign(numCourses,0);
                for(auto& info : prerequisites)
                {
                    adj[info.back()].emplace_back(info.front());
                    ++Indegree[info.front()];
                }
            }
            bool TopSort()
            {
                queue<int> Q;
                int count=0;
                for(int i=0;i<Indegree.size();++i)
                {
                    if(Indegree[i]==0)
                    {
                        Q.push(i);
                        while(!Q.empty())
                        {
                            int front=Q.front();
                            Q.pop();
                            ++count;
                            for(int& num : adj[front])
                            {
                                --Indegree[num];
                                if(Indegree[num]==0)
                                {
                                    Indegree[num]=-1;
                                    Q.push(num);
                                }
                            }
                        }
                    }
                }
                return count==Indegree.size();
            }
        };
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses,prerequisites);
        return g.TopSort();
    }
};
