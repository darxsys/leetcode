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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret;
        if (logs.empty() || n == 0) return ret;
        ret = vector<int>(n, 0);

        int i = 0;
        while (i < n)
            recurse(i, n, ret, logs);
        return ret;
    }

private:
    int recurse(int &i, int n, vector<int> &times, const vector<string>& logs)
    {
        logentry cur = parse(logs[i]);
        logentry next = parse(logs[i+1]);

        int total_time = 0;
        int this_time = 0;

        if (next.func == cur.func && cur.start == "start" && next.start == "end")
        {
            this_time = next.timestamp - cur.timestamp + 1;
            total_time = this_time;
            i += 2;
        }
        else
        {
            this_time = next.timestamp - cur.timestamp;
            total_time = this_time;

            ++i;
            while (next.func != cur.func || next.start != "end")
            {
                int inside = recurse(i, n, times, logs);
                total_time += inside;
                next = parse(logs[i]);
            }

            ++i;

            int rest_this = next.timestamp - cur.timestamp - total_time + 1;
            this_time += rest_this;
            total_time += rest_this;
        }

        times[cur.func] += this_time;
        return total_time;
    }

    struct logentry {
        int func;
        string start;
        int timestamp;
    };

    struct logentry parse(const string& log)
    {
        size_t first_colon = log.find(":");
        size_t second_colon = log.find(":", first_colon+1);

        int func = stoi(log.substr(0, first_colon));
        string start = log.substr(first_colon+1, second_colon-first_colon-1);
        int timestamp = stoi(log.substr(second_colon+1)); 
        
        return logentry{func, start, timestamp};
    }
};

int main()
{
    Solution s;
    vector<string> in = {"0:start:0",  "1:start:2", "1:end:5", "0:end:6"};
    //s.exclusiveTime(2, in);

    in = {"0:start:0","1:start:2","1:end:5","1:start:6","1:start:8", "1:end:10","1:end:12","0:end:14"};
    s.exclusiveTime(2, in);

    in = {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"};
    return 0;
}