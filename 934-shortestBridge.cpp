class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        int** group = new int*[rows];
        for (int i = 0; i < rows; ++i)
        {
            group[i] = new int[cols];
            memset(group[i], 0, sizeof(int)*cols);
        }


        int dires[5] = {1, 0, -1, 0, 1};

        int id = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (A[i][j] == 1 && group[i][j] == 0)
                {

                    stack<int> s;

                    s.push(i*cols + j);

                    ++id;
                    group[i][j] = id;

                    while (!s.empty())
                    {
                        int curr = s.top();
                        s.pop();
                        int x = curr / cols;
                        int y = curr % cols;
                        for (int i = 0; i < 4; ++i)
                        {

                            int nextX = x + dires[i];
                            int nextY = y + dires[i+1];
                            if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols
                                && A[nextX][nextY] == 1 && group[nextX][nextY] == 0)
                            {

                                group[nextX][nextY] = id;
                                s.push(nextX*cols + nextY);
                            }
                        }
                    }
                }
            }
        }

        unordered_set<int> targets;

        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (group[i][j] == 1)
                {
                    q.emplace(i, j);
                }
                else if (group[i][j] ==2)
                {
                    targets.insert(i*cols + j);
                }
            }
        }

        int depth = 0;
        while (!q.empty())
        {
            for (int i = q.size() -1; i >= 0; --i)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (targets.find(x*cols + y) == targets.end())
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        int nextX = x + dires[i];
                        int nextY = y + dires[i+1];
                        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols
                            && group[nextX][nextY] != 1)
                        {
                            group[nextX][nextY] = 1;
                            q.emplace(nextX, nextY);
                        }
                    }
                }
                else
                {
                    return depth -1 ;
                }
            }
            ++depth;
        }

        return -1;
    }
};