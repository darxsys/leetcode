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
        char buf[size+1];
        strcpy(buf, beginWord.c_str());
        for (int i = 0; i < size; ++i)
        {
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (j == beginWord[i]) continue;

                buf[i] = j;
                if (dictionary.find(buf) != dictionary.end())
                {
                    q.push_back(dictionary[buf]);
                    visited[dictionary[buf]] = 1;
                }
            }

            buf[i] = beginWord[i];            
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

                strcpy(buf, cur.c_str());
                for (int j = 0; j < size; ++j)
                {
                    for (char k = 'a'; k <= 'z'; ++k)
                    {
                        if (k == cur[j]) continue;

                        buf[j] = k;
                        // printf("%s\n", s.c_str());

                        if (dictionary.find(buf) != dictionary.end() && !visited[dictionary[buf]])
                        {
                            q.push_back(dictionary[buf]);
                            visited[dictionary[buf]] = 1;
                        }
                    }

                    buf[j] = cur[j];         
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