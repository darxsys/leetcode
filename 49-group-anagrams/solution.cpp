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


class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return vector<vector<string>>();

        int n = strs.size();
        vector<pair<int, int>> hashed;

        for (int i = 0; i < n; ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            hashed.push_back({hash(s), i});
        }

        sort(hashed.begin(), hashed.end(), compare);

        vector<string> v;
        v.push_back(strs[hashed[0].second]);
        vector<vector<string> > solution;
        int cur = 0;

        for (int i = 1; i < n; ++i)
        {
            if (hashed[i].first == hashed[cur].first)
            {
                v.push_back(strs[hashed[i].second]);
            }
            else
            {
                solution.push_back(v);
                v = {};
                v.push_back(strs[hashed[i].second]);
                cur = i;
            }
        }

        solution.push_back(v);

        return solution;
    }

private:
   static long long int hash(const string& s)
    {
        long long int mod = 1e9 + 9;
        int p = 31;

        long long int m = 1;
        long long int hash = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            hash += (m * (s[i] - 'a' + 1)) % mod;
            m = (m * p) % mod;
        }

        printf("%s %lld\n", s.c_str(), hash);
        return hash;
    }

    static bool compare(const pair<int, int>& first, const pair<int, int>& second)
    {
        return first.first < second.first;
    }
};

class Solution3 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return vector<vector<string>>();

        int n = strs.size();
        unordered_map<long long int, vector<string> > res;

        for (int i = 0; i < n; ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            long long int h = hash(s);

            if (res.find(h) == res.end())
            {
                res[h] = vector<string>({strs[i]});
            }
            else
            {
                res[h].push_back(strs[i]);
            }
        }

        vector<vector<string>> solution;
        for (const auto& any : res)
        {
            solution.push_back(any.second);
        }        

        return solution;
    }

private:
   static long long int hash(const string& s)
    {
        long long int mod = 1e9 + 9;
        int p = 31;

        long long int m = 1;
        long long int hash = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            hash += (m * (s[i] - 'a' + 1)) % mod;
            m = (m * p) % mod;
        }

        return hash;
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
    vector<string> input({"tea","and","ace","ad","eat","dans"});
    Solution2 s;

    vector<vector<string> > out = s.groupAnagrams(input);
    printVec(out);

    return 0;
}
