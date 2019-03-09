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
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.empty()) return true;
        ordinals.clear();

        int n = order.size();
        for (int i = 0; i < n; ++i)
        {
            ordinals[order[i]] = i;
        }

        vector<string> words2(words.size());
        for (int i = 0; i < words.size(); ++i)
        {
            words2[i] = words[i];
        }

        sort(words2.begin(), words2.end(), Compare);

        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i] != words2[i]) return false;
        }

        return true;
    }

private:
    static bool Compare(const string& first, const string& second)
    {
        int i = 0;
        int j = 0;
        while (i < first.size() && j < second.size() && first[i] == second[j])
        {
            i++;
            j++;
        }

        return i >= first.size() && j < second.size() || (i < first.size() && j < second.size() && ordinals[first[i]] < ordinals[second[j]]);
    }

    static unordered_map<char, int> ordinals;
};

unordered_map<char, int> Solution::ordinals = unordered_map<char, int>();

int main()
{
    Solution s;
    vector<string> input = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    assert(s.isAlienSorted(input, order) == true);

    input = {"word","world","row"};
    order = "worldabcefghijkmnpqstuvxyz";
    assert(s.isAlienSorted(input, order) == false);

    return 0;
}