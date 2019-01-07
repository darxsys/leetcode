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
        
        string output = "";
        solve(digits, 0, output, sol);
        return sol;
    }
private:
    void solve(const string& digits, int i, string& output, vector<string>& sol)
    {
        if (i == digits.size())
        {
            sol.emplace_back(output);
            return;
        }

        const string& characters = dictionary[digits[i] - '0' - 2];
        for (int j = 0; j < characters.size(); ++j)
        {
            string n = output;
            n.append(&characters[j], 1);
            solve(digits, i+1, n, sol);
        }
    }
    
    string dictionary[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
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