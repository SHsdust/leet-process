#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return 0;

        int m(board.size()), n(board[0].size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find(false);

        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                backtracking(i, j, board, word, find, visited, 0);

        return find;
    }

    void backtracking(int i, int j, vector<vector<char>> &board, string &word, bool& find, \
                      vector<vector<bool>> &visited, int pos)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return ;
        if(visited[i][j] || find || board[i][j]!=word[pos])
            return ;
        if(pos == word.size()-1){
            find = true;
            return ;
        }

        visited[i][j] = true;

        backtracking(i+1, j, board, word, find, visited, pos+1);
        backtracking(i-1, j, board, word, find, visited, pos+1);
        backtracking(i, j+1, board, word, find, visited, pos+1);
        backtracking(i, j-1, board, word, find, visited, pos+1);

        visited[i][j] = false;
    }
};

int main(){
    char arr[7][7] = {
        {"CAA"},{"AAA"},{"BCD"}
    };
    vector<char> a(arr[0], arr[0]+3);
    vector<char> b(arr[1], arr[1]+3);
    vector<char> c(arr[2], arr[2]+3);
    vector<vector<char>> board;
    board.push_back(a);
    board.push_back(b);
    board.push_back(c);

    string word("AAB");

    Solution s;
    cout << s.exist(board, word) << endl;
    return 0;
}
