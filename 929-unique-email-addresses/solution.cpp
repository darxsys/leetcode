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
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq;

        for (const string &s : emails)
        {
            size_t at = s.find("@", 0);
            string local = s.substr(0, at);
            local = local.substr(0, local.find("+", 0));
            local.erase(std::remove(local.begin(), local.end(), '.'), local.end());
            printf("%s\n", local.c_str());
            uniq.insert(local + s.substr(at));
        }

        return uniq.size();   
    }
};

int main()
{
    Solution s;
    vector<string> input({"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"});
    assert(s.numUniqueEmails(input) == 2);
    return 0;
}