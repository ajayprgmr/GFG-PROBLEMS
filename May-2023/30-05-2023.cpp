// C++ solution
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        int dx[] = { -1 , 1 ,  0  , 0};
        int dy[] = { 0  , 0 , -1  , 1};
        
        auto valid = [&](int x, int y, int p) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            if(vis[x][y])
                return 0;
                
            return board[x][y] == word[p];
        };
        
        function<bool(int, int, int)> dfs = [&](int x, int y, int p) -> bool {
            if(p == word.size() - 1)
                return 1;
                
            vis[x][y] = 1;
            
            bool ok = 0;
                
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny, p + 1))
                    ok = ok or dfs(nx, ny, p + 1);
            }
            
            vis[x][y] = 0;
            return ok;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(valid(i, j, 0) and dfs(i, j, 0))
                    return 1;
            }
        }
        
        return 0;
    }
};
