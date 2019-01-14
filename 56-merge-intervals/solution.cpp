#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
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

 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    bool operator<(const Interval& other)
    {
        return this->start < other.start || this->end < other.end;
    }
};
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return vector<Interval>();

        sort(intervals.begin(), intervals.end(), compare);        

        vector<Interval> res;
        int i = 0;
        int n = intervals.size();
        while (i < n)
        {
            Interval in(intervals[i].start, intervals[i].end);
            int j = i + 1;
            while (j < n && intervals[j].start <= in.end)
            {
                in.start = min(in.start, intervals[j].start);
                in.end = max(in.end, intervals[j].end);
                j++;
            }

            res.push_back(in);
            i = j;
        }

        return res;
    }
private:
    static bool compare(const Interval& left, const Interval& right)
    {
        return left.start < right.start;
    }
};

void printVec(const vector<Interval>& intervals)
{
    printf("[");
    for (int i = 0; i < intervals.size(); ++i)
    {
        printf("[%d %d] ", intervals[i].start, intervals[i].end);
    }

    printf("]\n");
}

int main()
{
    Solution s;
    vector<Interval> input({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    printVec(s.merge(input));

    input = {{1,4}, {4, 5}};
    printVec(s.merge(input));

    input = {{1,4}, {4, 5}, {5, 10}, {6, 25}, {30, 40}};
    printVec(s.merge(input));

    input = {{1,4}, {0, 4}};
    printVec(s.merge(input));

    input = {{1,4}, {0, 0}};
    printVec(s.merge(input));

    input = {{1000,2000},{990,2010},{980,2020},{970,2030},{960,2040},{950,2050},{940,2060},{930,2070},{920,2080},{910,2090},{900,2100},{890,2110},{880,2120},{870,2130},{860,2140},{850,2150},{840,2160},{830,2170},{820,2180},{810,2190},{800,2200},{790,2210},{780,2220},{770,2230},{760,2240},{750,2250},{740,2260},{730,2270},{720,2280},{710,2290},{700,2300},{690,2310},{680,2320},{670,2330},{660,2340},{650,2350},{640,2360},{630,2370},{620,2380},{610,2390},{600,2400},{590,2410},{580,2420},{570,2430},{560,2440},{550,2450},{540,2460},{530,2470},{520,2480},{510,2490},{500,2500},{490,2510},{480,2520},{470,2530},{460,2540},{450,2550},{440,2560},{430,2570},{420,2580},{410,2590},{400,2600},{390,2610},{380,2620},{370,2630},{360,2640},{350,2650},{340,2660},{330,2670},{320,2680},{310,2690},{300,2700},{290,2710},{280,2720},{270,2730},{260,2740},{250,2750},{240,2760},{230,2770},{220,2780},{210,2790},{200,2800},{190,2810},{180,2820},{170,2830},{160,2840},{150,2850},{140,2860},{130,2870},{120,2880},{110,2890},{100,2900},{90,2910},{80,2920},{70,2930},{60,2940},{50,2950},{40,2960},{30,2970},{20,2980},{10,2990}};
    printVec(s.merge(input));

    return 0;
}