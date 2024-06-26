#include <iostream>
#include <stack>
using namespace std;

int sum = 1;
int result = 0;
stack<char> bracketStack;
int main()
{
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            bracketStack.push(str[i]);
            sum *= 2;
        }
        if(str[i] == '[')
        {
            bracketStack.push(str[i]);
            sum *= 3;
        }
        if(str[i] == ')')
        {
            if(bracketStack.empty() || bracketStack.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(') 
            {
                result += sum;
            }
            bracketStack.pop();
            sum /= 2;
        }
        if(str[i] == ']')
        {
            if(bracketStack.empty() || bracketStack.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') 
            {
                result += sum;
            }
            bracketStack.pop();
            sum /= 3;
        }
    }

    if(bracketStack.empty())
    {
        cout << result;
    } 
    else
    {
        cout << 0;
    }
}