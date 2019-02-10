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
            char c = beginWord[i];
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (j == c) continue;

                beginWord[i] = j;
                if (dictionary.find(beginWord) != dictionary.end())
                {
                    q.push_back(dictionary[beginWord]);
                    visited[dictionary[beginWord]] = 1;
                } 
            }

            beginWord[i] = c;            
        }

        while (!q.empty())
        {
            dist++;
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                string& cur = wordList[q.front()];
                q.pop_front();

                if (cur == endWord)
                {
                    return dist+1;
                }

                for (int j = 0; j < size; ++j)
                {
                    char c = cur[j];
                    for (char k = 'a'; k <= 'z'; ++k)
                    {
                        if (k == c) continue;

                        cur[j] = k;
                        if (dictionary.find(cur) != dictionary.end() && !visited[dictionary[cur]])
                        {
                            q.push_back(dictionary[cur]);
                            visited[dictionary[cur]] = 1;
                        }
                    }

                    cur[j] = c;       
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