class Solution {
public:
    //当前状态的i和j能否交换，有一个为0就可以
    void change_map(string str, int i, int j, queue<int> &q) {
        if(str[i] == '0' || str[j] == '0') {
            swap(str[i], str[j]);
            q.push(atoi(str.c_str()));      //bfs遍历，添加新的状态
        }
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        set<int> path;
        int res = 0;
        //初始状态
        int status = board[0][0] * 100000 + board[0][1] * 10000 + board[0][2] * 1000 +
                     board[1][0] * 100 + board[1][1] * 10 + board[1][2];
        queue<int> bfs_path({status});
        int change_pair[7][2] = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {0, 3}, {1, 4}, {2, 5}};
        while(!bfs_path.empty()) {
            int len = bfs_path.size();
            for (int i = 0; i < len; i++) {
                status = bfs_path.front();
                bfs_path.pop();
                if(status == 123450) return res;    //停止状态1
                if(status == 132450) return -1;     //停止状态2
                if(path.find(status) != path.end()) continue;   //走过的跳过
                string str = to_string(status);
                if(str.size() == 5) str = "0" + str;
                for (int j = 0; j < 7; j++)     //7种交换方法 左右4种，上下3种
                    change_map(str, change_pair[j][0], change_pair[j][1], bfs_path);
                path.insert(status);        //走过的路标记防止重复走
            }
            res++;  //更新,步数+1
        }
        return res;
    }
};