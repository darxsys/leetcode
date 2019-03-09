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

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if (m_buf != buf)
        {
            in.clear();
            m_buf = buf;
            i = 0;
        }
        
        if (in.size() - i < n)
        {
            int k = 0;
            while (k < n)
            {
                char p[5];
                int r = read4(p);
                p[r] = '\0';
                if (r > 0)
                {
                    in += p;
                }

                if (r < 4) break;

                k += 4;
            }
        }
        
        int c = n;
        int j = i;
        while (i < in.size() && c > 0)
        {
            buf[i - j] = in[i];
            c--;
            i++;
        }
        
        buf[i-j] = '\0';
        return i-j;
    }
private:
    string in;
    char *m_buf = nullptr;
    int i = 0;
};

int main()
{
    return 0;
}