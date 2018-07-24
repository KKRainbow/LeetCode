class Solution
{
    int rowCnt, colCnt;
    vector<pair<int, int>> pairs;

  public:
    bool isOpen(vector<vector<char>> &board, vector<vector<char>> &visited, int i, int j)
    {
        if (i < 0 || i >= rowCnt || j < 0 || j >= colCnt)
        {
            return true;
        }
        if (visited[i][j] == '1') 
        {
            return false;
        }
        visited[i][j] = '1';
        if (board[i][j] == 'X')
        {
            return false;
        }
        else
        {
            pairs.push_back({i, j});
            bool a = isOpen(board, visited, i - 1, j);
            bool b = isOpen(board, visited, i + 1, j);
            bool c = isOpen(board, visited, i, j - 1);
            bool d = isOpen(board, visited, i, j + 1);
            return a || b || c || d;
        }
    }
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        rowCnt = board.size();
        colCnt = board[0].size();
        auto visited = board;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                pairs.clear();
                if (!isOpen(board, visited, i, j)) {
                    for (auto p : pairs) {
                        board[p.first][p.second] = 'X';
                    }
                }
            }
        }
    }
};

