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
#include <unordered_set>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";

        int n = words.size();
        vector<bool> v(26);
        vector<vector<bool>> graph(26, v);
        vector<int> indegree(26, 0);
        unordered_set<char> chars;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
                chars.insert(words[i][j]);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int k = 0;
                string &s1 = words[i];
                string &s2 = words[j];

                while (k < s1.size() && k < s2.size())
                {
                    if (s1[k] != s2[k])
                    {
                        if (!graph[s1[k]-'a'][s2[k] - 'a'])
                        {
                            graph[s1[k]-'a'][s2[k] - 'a'] = true;
                            indegree[s2[k]-'a']++;
                        }
                        break;
                    }

                    k++;
                }
            }
        }

        int visited = 0;
        queue<char> q;
        for (char c : chars)
        {
            if (indegree[c-'a'] == 0)
                q.push(c);
        }

        string sol = "";

        while (!q.empty())
        {
            char c = q.front();
            visited++;
            q.pop();
            sol = sol + c;

            for (int i = 0; i < 26; ++i)
            {
                if (graph[c-'a'][i])
                {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        q.push(i + 'a');
                }
            }
        }

        return visited == chars.size() ? sol : "";
    }
};

int main()
{
    Solution s;
    vector<string> input({"wrt", "wrf", "er", "ett", "rftt"});
    printf("%s\n", s.alienOrder(input).c_str());

    input = {"z", "x", "z"};
    printf("%s\n", s.alienOrder(input).c_str());

    input = {"z", "x"};
    printf("%s\n", s.alienOrder(input).c_str());
    return 0;
}