#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> operators;
        deque<int> numbers;

        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                char digits[13];
                digits[0] = s[i];

                int j = i;
                while (i + 1 < s.size() && isdigit(s[i+1]))
                {
                    digits[i+1-j] = s[i+1];
                    i++;
                }

                digits[i+1-j] = '\0';
                numbers.push_back(atoi(digits));
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (!operators.empty() && operators.top() != '(')
                {
                    char op = operators.top();
                    operators.pop();

                    int a = numbers.back();
                    numbers.pop_back();
                    int b = numbers.back();
                    numbers.pop_back();

                    if (op == '-')
                        numbers.push_back(b-a);
                    else
                        numbers.push_back(a+b);

                }

                operators.push(s[i]);
            }
            else if (s[i] == '(')
            {
                operators.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (operators.top() != '(')
                {
                    char op = operators.top();
                    operators.pop();

                    int a = numbers.back();
                    numbers.pop_back();
                    int b = numbers.back();
                    numbers.pop_back();

                    if (op == '-')
                        numbers.push_back(b-a);
                    else
                        numbers.push_back(a+b);
                }

                operators.pop();
            }

        }   

        int res = 0;
        if (operators.empty())
            res = numbers.front();
        else
        {

            while (!operators.empty())
            {
                char op = operators.top();
                operators.pop();

                int a = numbers.back();
                numbers.pop_back();

                int b = numbers.back();
                numbers.pop_back();

                res += op == '-' ? b - a : a + b;
            }
        }

        return res;  
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.calculate("2147483647"));
    printf("%d\n", s.calculate("1+1"));
    printf("%d\n", s.calculate(" 2-1 + 2 "));
    printf("%d\n", s.calculate("(1+(4+5+2)-3)+(6+8)"));
    return 0;
}