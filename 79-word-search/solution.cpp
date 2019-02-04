#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] != word[0]) continue;

                if (find(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
private:
    bool find(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        if (index == word.size()) return true;

        if (i < 0 || i >= board.size()) return false;
        if (j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[index]) return false;


        char c = board[i][j];
        board[i][j] = '\0';
        bool ret = false;
        for (int k = 0; k < 4; ++k)
        {
            if (find(board, word, i + rowDir[k], j + colDir[k], index+1))
            {
                ret = true;
                break;
            }

        }

        board[i][j] = c;
        return ret;
    }

    vector<int> rowDir = {-1, 1, 0, 0};
    vector<int> colDir = {0, 0, 1, -1};
};

int main()
{
    Solution s;
    vector<vector<char> > m = {
          {'A','B','C','E'},
          {'S','F','C','S'},
          {'A','D','E','E'}
        };

    assert(s.exist(m, "ABCCED") == true);
    assert(s.exist(m, "SEE") == true);
    assert(s.exist(m, "ABCB") == false);
    return 0;
}