class Solution {
public:

    int dfs(const vector<vector<int>>& matrix,vector<vector<int>>& mem, int x, int y, int m, int n, int len){
        if (mem[x][y]!=0){
            return mem[x][y];
        }
        int maxLen = len;
        if (x-1>=0 && matrix[x-1][y] > matrix[x][y]){
            maxLen = max(maxLen, dfs(matrix,mem,x-1,y,m,n,len+1));
        }
        if (x+1<=m-1 && matrix[x+1][y] > matrix[x][y]){
            maxLen = max(maxLen, dfs(matrix,mem,x+1,y,m,n,len+1));
        }
        if (y-1>=0 && matrix[x][y-1] > matrix[x][y]){
            maxLen = max(maxLen, dfs(matrix,mem,x,y-1,m,n,len+1));
        }
        if (y+1<=n-1 && matrix[x][y+1] > matrix[x][y]){
            maxLen = max(maxLen, dfs(matrix,mem,x,y+1,m,n,len+1));
        }

        mem[x][y] = maxLen;
        std::cout << "x : " << x << " y : " << y << mem[x][y] << std::endl;
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //left, right, up, down
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mem(matrix);
        for (int i = 0;i<m;i++){
            for (int j =0;j<n;j++){
                matrix[i][j] = 0;
            }
        }
        int maxLen = 1;
        for (int i = 0;i<m;i++){
            for (int j =0;j<n;j++){
                maxLen = max(maxLen, dfs(matrix,mem,i,j,m,n,1));
            }
        }
        return maxLen;
    }
};