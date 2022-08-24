#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    void backtracking(int i, int j, vector<vector<char>>& board, string& word, bool
                      & find, vector<vector<bool>>& visited, int pos) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        if (visited[i][j] || find || board[i][j] != word[pos]) {
            return;
        }
        if (pos == word.size() - 1) {
            find = true;
            return;
        }

        visited[i][j] = true;
        backtracking(i + 1, j, board, word, find, visited, pos + 1);
        backtracking(i - 1, j, board, word, find, visited, pos + 1);
        backtracking(i, j + 1, board, word, find, visited, pos + 1);
        backtracking(i, j - 1, board, word, find, visited, pos + 1);
        visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtracking(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }

};

int main(){
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word{"SEE"};
    Solution s;
    cout << s.exist(board, word) << endl;
    return 0;
}
