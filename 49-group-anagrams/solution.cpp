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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return vector<vector<string>>();

        int n = strs.size();
        vector<pair<string, int>> cpy;

        for (int i = 0; i < n; ++i)
        {
            cpy.push_back({strs[i], i});
            sort(cpy[i].first.begin(), cpy[i].first.end());
        }

        sort(cpy.begin(), cpy.end(), compare);

        vector<string> v;
        v.push_back(strs[cpy.begin()->second]);
        vector<vector<string> > solution;
        int cur = 0;

        for (int i = 1; i < n; ++i)
        {
            if (cpy[i].first == cpy[cur].first)
            {
                v.push_back(strs[cpy[i].second]);
            }
            else
            {
                solution.push_back(v);
                v = {};
                v.push_back(strs[cpy[i].second]);
                cur = i;
            }
        }

        solution.push_back(v);

        return solution;
    }

private:
   static bool compare(const pair<string, int>& first, const pair<string, int>& second)
    {
        return first.first < second.first;
    }
};

void printVec(vector<vector<string> >& vec)
{
    printf("[\n");
    for (int i = 0; i < vec.size(); ++i)
    {
        printf("[");
        for (int j = 0; j < vec[i].size(); ++j)
        {
            printf("%s,", vec[i][j].c_str());
        }
        printf("]\n");
    }
    printf("]\n");
}

int main()
{
    vector<string> input({"eat", "tea", "tan", "ate", "nat", "bat"});
    Solution s;

    vector<vector<string> > out = s.groupAnagrams(input);
    printVec(out);

    return 0;
}
