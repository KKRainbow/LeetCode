class Solution {
    vector<vector<char>> board;
    vector<vector<pair<int, int>>> pos;
    string str;
    bool bfs(int idx, pair<int, int> ppos) {
        if (idx == str.length()) return true;
        for (auto& coord : pos[str[idx]]) {
            int x = coord.first, y = coord.second;
            int dist = abs(ppos.first - x) + abs(ppos.second - y);
            bool first = ppos.first < 0; 
            if ((first || dist == 1) && board[x][y] == str[idx]) {
                board[x][y] = 0;
                bool res = bfs(idx + 1, make_pair(x, y));
                if (res) {
                    return true;
                }
                board[x][y] = str[idx];
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<pair<int, int>>> posTable(256);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                posTable[board[i][j]].push_back(make_pair(i, j));
            }
        }
        this->board = board;
        this->str = word;
        this->pos = posTable;
        return bfs(0, make_pair(-1, -1));
    }
};
