// 20.Add Binary
#include <iostream>
#include <stack>
using namespace std;

//제출 코드 
//참고하고했음 : https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/67.%20Add%20Binary.cpp
//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Add Binary.
//Memory Usage : 6.3 MB, less than 56.64 % of C++ online submissions for Add Binary.
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = max(a.size(), b.size()) + 1;
        a.insert(a.begin(), n - a.size(), '0');
        b.insert(b.begin(), n - b.size(), '0');

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int next = 0;
        for (int i = 0; i < n; i++)
        {
            int ai = a[i] - '0';
            int bi = b[i] - '0';
            int sum = ai + bi + next;
            switch (sum)
            {
                case 0:
                    ans.push_back('0');
                    next = 0;
                    break;
                case 1:
                    ans.push_back('1');
                    next = 0;
                    break;
                case 2:
                    ans.push_back('0');
                    next = 1;
                    break;
                case 3:
                    ans.push_back('1');
                    next = 1;
                    break;
            }
        }
        if (ans[n - 1] == '0') ans.resize(n - 1);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("11","1") << endl;
}