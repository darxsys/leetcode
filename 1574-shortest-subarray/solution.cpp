class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() <= 1) return 0;
        
        int n = arr.size();
        
        int left = 0;
        int right = n-1;
        
        while (left < right) {
            if (arr[left] <= arr[left+1]) left++;
            else if (arr[right] >= arr[right-1]) right--;
            else break;
        }
        
        if (left >= right) return 0;
        
        int result = n-1;
        int curLeft = 0;
        int curRight = right;

        while (curLeft <= left) {
            if (curRight == n || arr[curRight] >= arr[curLeft]) {
                result = min(result, curRight-curLeft-1);
                curLeft++;
            } else if (curRight < n) {
                curRight++;
            }
        }
        
        curLeft = left;
        curRight = n-1;
        while (curRight >= right) {
            if (curLeft < 0 || arr[curLeft] <= arr[curRight]) {
                result = min(result, curRight-max(curLeft, 0));
                curRight--;
            } else if (curLeft >= 0) {
                curLeft--;
            }
        }
        
        return result;
    }
};;