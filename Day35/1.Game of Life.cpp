#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int alive = 0;

                for (int d = 0; d < 8; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];

                    if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) {
                        if (board[x][y] == 1 || board[x][y] == 10) {
                            alive++;
                        }
                    }
                }

                int curr = board[i][j];

                
                if (curr == 1 && (alive < 2 || alive > 3)) {
                    board[i][j] = 10; 
                } else if (curr == 0 && alive == 3) {
                    board[i][j] = 11;
                }
            }
        }

        
        for (auto &i : board) {
            for (auto &j : i) {
                if (j == 10) {
                    j = 0;
                } else if (j == 11) {
                    j = 1;
                }
            }
        }
    }
};
