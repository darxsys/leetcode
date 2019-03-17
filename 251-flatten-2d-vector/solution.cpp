#include <cstdio>
#include <cstring>
#include <climits>
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

class Vector2D {
public:
    Vector2D(vector<vector<int>> v) {
        vec = v;
        cur_vec = 0;
        cur_elem = -1;
        moveToNext();
    }
    
    int next() {
        int ret = vec[cur_vec][cur_elem];
        moveToNext();
        return ret;
    }
    
    bool hasNext() {
        return cur_vec < vec.size();
    }
    
private:
    void moveToNext()
    {
        cur_elem++;
        if (cur_vec < vec.size() && cur_elem == vec[cur_vec].size())
        {
            cur_vec++;
            cur_elem = 0;
            while (cur_vec < vec.size() && cur_elem == vec[cur_vec].size()) cur_vec++;
        }
    }
    
    int cur_vec = 0;
    int cur_elem = 0;
    vector<vector<int>> vec;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    return 0;
}