class Solution {
public:

    bool solve(int row, int col,
               vector<vector<char>>& board,
               string &word,
               int idx,
               vector<vector<bool>> &visit){

        int m = board.size();
        int n = board[0].size();

        if(idx == word.size())
            return true;

        if(row < 0 || row >= m || col < 0 || col >= n)
            return false;

        if(visit[row][col])
            return false;

        if(board[row][col] != word[idx])
            return false;

        visit[row][col] = true;

        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};

        for(int k=0;k<4;k++){
            if(solve(row+dx[k], col+dy[k], board, word, idx+1, visit)){
                return true;
            }
        }

        visit[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(i,j,board,word,0,visit))
                    return true;
            }
        }

        return false;
    }
};