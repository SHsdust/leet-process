#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "cstdio"
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 0) {
            return ans;
        }
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }


    void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<
                      bool> &column, vector<bool> &ldiag, vector<bool> &rdiag, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (column[i] || ldiag[n-row+i-1] || rdiag[row+i]) {
                continue;
            }
            board[row][i] = 'Q';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            backtracking(ans, board, column, ldiag, rdiag, row+1, n);
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }
    }
};

int main(){
    int n;
    while( cin >> n){
        Solution s;
        vector<vector<string>> res = s.solveNQueens(n);
        for(auto p=res.begin(); p!=res.end(); ++p){
            printf("[");
            for(auto q=p->begin(); q!=p->end(); q++){
                if(q==(*p).begin())
                    printf("[");
                cout << "\"" << *q << "\",";
            }
            printf("],");
        }
        printf("]\n");
    }
    return 0;
}
