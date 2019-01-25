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
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0) return 0;

        vector<int> count(26, 0);
        int num = tasks.size();
        for (int i = 0; i < num; ++i)
        {
            count[tasks[i] - 'A']++;
        }

        priority_queue<int> q;
        for (int i = 0; i < 26; ++i)
        {
            if (count[i] > 0)
                q.push(count[i]);
        }

        int time = 0;
        int save[26];
        while (true)
        {
            if (q.empty())
                break;

            int count_cur = 0;
            int j = -1;
            for (int i = 0; i < n + 1; ++i)
            {
                count_cur++;
                int task_count = q.top();
                q.pop();
                if (task_count > 1)
                    save[++j] = task_count-1;

                if (q.empty())
                    break;
            }

            time += j == -1 ? count_cur : n + 1;
            while (j >= 0)
            {
                q.push(save[j--]);
            }            
        }

        return time;
    }
};

int main()
{
    Solution s;

    vector<char> tasks({'A','A','A','B','B','B'});
    int n = 2;

    assert(s.leastInterval(tasks, n) == 8);
    return 0;
}