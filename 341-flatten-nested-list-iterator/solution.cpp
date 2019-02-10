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


 class NestedInteger {
 public:
    NestedInteger(int a)
    {
        m_fInteger = true;
        i = a;
    }

    NestedInteger(vector<NestedInteger> v)
    {
        list = v;
        m_fInteger = false;
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return m_fInteger;
    }
 
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return i;
    }

    const vector<NestedInteger> &getList() const
    {
        return list;
    }

private:
    vector<NestedInteger> list;
    int i = -1;
    bool m_fInteger = false;
};
 
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        curVec = &nestedList;
        i = 0;
    }

    int next() {
        return curVec->at(i++).getInteger();
    }

    bool hasNext() {
        while(i >= curVec->size() && !save.empty())
        {
            curVec = save.top().first;
            i = save.top().second;
            save.pop();
        } 
        
        if (i >= curVec->size()) return false;

        const NestedInteger* cur = &curVec->at(i);

        while(!cur->isInteger())
        {
            if (!cur->getList().empty())
            {
                save.push({curVec, ++i});
                curVec = &cur->getList();
                i = 0;
                cur = &curVec->at(i);
            }
            else
            {
                ++i;
                while ((i >= curVec->size()) && !save.empty())
                {
                    curVec = save.top().first;
                    i = save.top().second;
                    save.pop();
                }

                if (i >= curVec->size()) return false;
                cur = &curVec->at(i);
            }
        }

        return i < curVec->size();
    }

private:
    const vector<NestedInteger> *curVec = nullptr;
    int i;
    stack<pair<const vector<NestedInteger>*, int> > save;
};


int main()
{
    vector<NestedInteger> v = {{1}, {1}};
    vector<NestedInteger> v2 = {{1}, {1}};
    vector<NestedInteger> input = {v, 2, v2};
    NestedIterator s(input);

    while (s.hasNext())
       printf("%d ", s.next());
    printf("\n");

    vector<NestedInteger> v3;
    NestedIterator s2(v3);
    while (s2.hasNext())
       printf("%d ", s2.next());
    printf("\n"); 
    
    vector<NestedInteger> v4({{vector<NestedInteger>()}});
    NestedIterator s3(v4);
    while (s3.hasNext())
       printf("%d ", s3.next());
    return 0;
}