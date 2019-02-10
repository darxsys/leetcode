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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        deque<int> q;

        int num_words = wordList.size();
        vector<int> visited(num_words, 0);
        unordered_map<string, int> dictionary;

        for (int i = 0; i < num_words; ++i)
        {
            dictionary[wordList[i]] = i;
        }

        int dist = 0;
        int size = beginWord.size();
        for (int i = 0; i < size; ++i)
        {
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (j == beginWord[i]) continue;

                string s = beginWord.substr(0, i) + j + beginWord.substr(i+1, size-i);
                // printf("%s\n", s.c_str());
                if (dictionary.find(s) != dictionary.end())
                {
                    q.push_back(dictionary[s]);
                    visited[dictionary[s]] = 1;
                }
            }            
        }

        while (!q.empty())
        {
            dist++;
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                const string& cur = wordList[q.front()];
                q.pop_front();

                if (cur == endWord)
                {
                    return dist+1;
                }

                for (int j = 0; j < size; ++j)
                {
                    for (char k = 'a'; k <= 'z'; ++k)
                    {
                        if (k == cur[j]) continue;

                        string s = cur.substr(0, j) + k + cur.substr(j+1, size-j);
                        // printf("%s\n", s.c_str());

                        if (dictionary.find(s) != dictionary.end() && !visited[dictionary[s]])
                        {
                            q.push_back(dictionary[s]);
                            visited[dictionary[s]] = 1;
                        }
                    }         
                }
            }
        }

        return 0;
    }
};


int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string begin = "hit";
    string end = "cog";
    Solution s;
    //printf("%d\n", s.ladderLength(begin, end, wordList));
    assert(s.ladderLength(begin, end, wordList) == 5);
    return 0;
}