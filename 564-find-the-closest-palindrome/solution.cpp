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
    string nearestPalindromic(string n) {
        int len = n.size();
        int mid = len % 2 ? len / 2 : len / 2 - 1;
        
        string pal = n;
        
        for (int i = mid + 1; i < len; ++i)
        {
            pal[i] = pal[len-i-1];
        }
        
        long long int num1 = stoll(n);
        long long int num2 = stoll(pal);
        
        if (pal == n)
        {
            string upper = pal;
            increment(upper);
            decrement(pal);
            
            long long int num_upper = stoll(upper);
            long long int num_lower = stoll(pal);
            
            if (abs(num_upper-num1) < abs(num_lower-num1)) return upper;
            
            return pal;
        }
        else if (pal > n)
        {
            string lower = pal;
            decrement(lower);
            
            long long int num_lower = stoll(lower);
            printf("%lld\n", num_lower);
            if (abs(num2-num1) < abs(num_lower-num1)) return pal;
            
            return lower;
        }
        else
        {
            string upper = pal;
            increment(upper);
            
            long long int num_upper = stoll(upper);
            
            if (abs(num_upper-num1) < abs(num2-num1)) return upper;
            return pal;
        }
        
        return "";
    }
private:
    void increment(string& s)
    {
        int len = s.size();
        int mid = len % 2 ? len / 2 : len / 2 - 1;
        
        if (len % 2)
        {
            s[mid]++;
            if (s[mid] <= '9') return;
            
            s[mid] = '0';
            mid--;
        }
        
        while (mid >= 0)
        {
            s[mid]++;
            s[len-mid-1]++;
            
            if (s[mid] > '9')
            {
                s[mid] = '0';
                s[len-mid-1] = '0';
                mid--;
                continue;
            }
            
            break;
        }
        
        if (mid < 0)
        {
            s[0] = '1';
            s.push_back('1');
        }
    }
    
    void decrement(string& s)
    {
        int len = s.size();
        int mid = len % 2 ? len / 2: len / 2 - 1;
        
        if (len % 2)
        {
            s[mid]--;
            if (s[mid] >= '0') return;
            
            s[mid] = '9';
            mid--;
        }
        
        while (mid >= 0)
        {
            s[mid]--;
            s[len-mid-1]--;
            
            if (s[mid] < '0')
            {
                s[mid] = '9';
                s[len-mid-1] = '9';
                mid--;
                continue;
            }
            
            break;
        }
        
        if (s[0] == '0')
        {
            s[0] = '9';
            s.pop_back();
        }        
    }
};

int main()
{
    return 0;
}