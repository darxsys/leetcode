#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0)
            return median(nums2, 0, nums2.size());
        else if (nums2.size() == 0)
            return median(nums1, 0, nums1.size());
        
        int m = nums1.size();
        int n = nums2.size();
        vector<int> &A = nums1;
        vector<int> &B = nums2;

        int sum_all = m + n;
        
        int i = m;
        int j = (sum_all - 2 * i + sum_all % 2) / 2;

        do 
        {
        	if (i < 0)
        	{
        		j /= 2;
        		i = (sum_all - 2 * j + sum_all % 2) / 2;
        		continue;
        	}
        	else if (j < 0)
        	{
        		i /= 2;
        		j = (sum_all - 2 * i + sum_all % 2) / 2;
        		continue;
        	}

	        if (i == 0)
	        {
	            if (sum_all % 2) return B[j-1];
	            else
	            {
	                if (j == n)
	                {
	                    return (A[0] + B[n-1]) / 2.;
	                }
	                else
	                {
	                    return (B[j-1] + min(A[0], B[j])) / 2.;
	                }
	            }
	        }
	        
	        if (j == 0)
	        {
	            if (sum_all % 2) return A[i-1];
	            else
	            {
	                if (i == m)
	                {
	                    return (A[m-1] + B[0]) / 2.;
	                }
	                else
	                {
	                    return (A[i-1] + min(B[0], A[i])) / 2.;
	                }
	            }
	        }
	        
	        if (i == m)
	        {
	            if (sum_all % 2) return max(A[i-1], B[j-1]);
	            else return (max(A[i-1], B[j-1]) + B[j]) / 2.;
	        }
	        
	        if (j == n)
	        {
	            if (sum_all % 2) return max(A[i-1], B[j-1]);
	            else return (max(A[i-1], B[j-1]) + A[i]) / 2.;
	        }

	        if (sum_all % 2) return max(nums1[i-1], nums2[j-1]);     
	        return (max(nums1[i-1], nums2[j-1]) + min(nums1[i], nums2[j])) / 2.;

        
            if (j < n && i > 0 && nums1[i-1] > nums2[j])
            {
                i = i/2+1;
                j = (sum_all - 2 * i + sum_all % 2) / 2;
            }
            else if (j > 0 && i < m && nums2[j-1] > nums1[i])
            {
                j = j/2;
                i = (sum_all - 2 * j + sum_all % 2) / 2;
            }
        } while (true);   

    }
    
private:
    double median(vector<int>& nums, int i, int j)
    {
        int size = j-i;
        if (size == 1) return nums[0];
        if (size % 2)
            return nums[size / 2];
        else
        {
            int a = nums[size / 2-1];
            int b = nums[size / 2];
            
            return (a + b) / 2.;
        }
    }
};

int main(void)
{
    Solution s;
    
    vector<int> v({2, 3, 5});
    vector<int> v2({1, 4});
    
    printf("%lf\n", s.findMedianSortedArrays(v, v2));
    return 0;
}
