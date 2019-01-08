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
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<int>();

        int n = nums.size();
        unordered_map<int, int> m;

        vector<int> clone = nums;
        sort(clone.begin(), clone.end());
        for (int i = 0; i < n; ++i)
            m[clone[i]] = i+1;

        vector<int> tree(n+1, 0);

        for (int i = n-1; i>= 0; --i)
        {
            clone[i] = query(tree, m[nums[i]]-1);
            add(tree, m[nums[i]]);
        }

        return clone;
    }
private:
    int query(const vector<int>& tree, int index)
    {
        int sol = 0;
        while (index > 0)
        {
            sol += tree[index];
            index = index - (index & -index);
        }

        return sol;
    }

    void add(vector<int>& tree, int index)
    {
        int n = tree.size()-1;
        while (index <= n)
        {
            tree[index] += 1;
            index = index + (index & -index);
        }
    }

};

int main()
{
    Solution s;
    vector<int> input({5, 2, 6, 1});
    vector<int> out = s.countSmaller(input); 
    for (int i = 0; i < out.size(); ++i)
        printf("%d ", out[i]);
    printf("\n");
    return 0;
}