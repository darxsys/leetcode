#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return vector<string>();

        vector<string> sol;
        
        char* output = new char[digits.size()+1];
        solve(digits, 0, output, sol);
        return sol;
    }
private:
    void solve(const string& digits, int i, char* output, vector<string>& sol)
    {
        if (i == digits.size())
        {
            output[i] = '\0';
            sol.emplace_back(output);
            return;
        }

        const char* characters = dictionary[digits[i] - '0' - 2];
        for (int j = 0; characters[j] != '\0'; ++j)
        {
            output[i] = characters[j];
            solve(digits, i+1, output, sol);
        }
    }
    
    char dictionary[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};


int main()
{
    string input = "23";
    Solution s;

    vector<string> result = s.letterCombinations(input);
    for (int i = 0; i < result.size(); ++i)
    {
        printf("%s ", result[i].c_str());
    }
    printf("\n");
    return 0;
}