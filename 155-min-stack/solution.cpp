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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push({x, s.empty() ? x : min(x, s.top().second)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
private:
    stack<pair<int, int> > s;
};

int main()
{
    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);
    assert(m.getMin() == -3);
    m.pop();
    assert(m.top() == 0);
    assert(m.getMin() == -2);
    return 0;
}