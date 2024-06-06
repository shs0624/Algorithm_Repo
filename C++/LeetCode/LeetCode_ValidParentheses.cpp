// 20.Valid Parentheses
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

// 0ms, 6.4mb? 내 코드
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = { {'(',')'}, {'{','}'},{'[',']'} };
        stack<char> st;
        char c;
        for (int i = 0; i < s.length(); i++)
        {
            if (!map.count(s[i]))
            {
                if (st.empty())
                {
                    return false;
                }

                c = st.top();
                st.pop();

                if (map[c] != s[i])
                {
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (!st.empty())
        {
            return false;
        }
        return true;
    }
};

// 2ms, 7.31mb - 전부 if로 체크하는 경우.
/*
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty() || (st.top() == '(' && s[i] != ')') || (s[i] != ']' && st.top() == '[') || (s[i] != '}' && st.top() == '{'))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
*/

int main()
{
    Solution s;
    cout << s.isValid("()[]{") << endl;
}