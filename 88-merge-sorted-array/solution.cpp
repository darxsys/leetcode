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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        vector<int> all(m + n, 0);

        int i = 0;
        int j = 0;

        while (true)
        {
            if (i < m && j < n && nums1[i] <= nums2[j] || i < m && j == n)
            {
                all[i + j] = nums1[i];
                i++;
            }
            else if (j < n && i < m && nums1[i] > nums2[j] || j < n && i == m)
            {
                all[i + j] = nums2[j];
                j++;
            }
            else
            {
                break;
            }
        }

        for (int k = 0; k < m + n; ++k)
        {
            nums1[k] = all[k];
        }
    }
};

void printVec(const vector<int>& vec)
{
    int n = vec.size();
    printf("[");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", vec[i]);
    }

    printf("]\n");
}


int main()
{
    Solution s;
    vector<int> input1 = {1,2,3,0,0,0};
    vector<int> input2 = {2, 5, 6};
    s.merge(input1, 3, input2, 3);
    printVec(input1);
    return 0;
}