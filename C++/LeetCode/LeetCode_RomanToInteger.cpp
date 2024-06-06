// 13. Roman to Integer
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

// I = 1,   V = 5
// X = 10,  L = 50
// C = 100, D = 500,    M = 1000

//46ms, 8.3 MB 내코드
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> map = { {'I', 1}, {'V', 5},{'X',10}, {'L',50}, {'C',100}, {'D', 500}, {'M', 1000} };
        int answer = 0;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (map[s[i]] < map[s[i + 1]])
            {
                answer -= map[s[i]];
            }
            else
            {
                answer += map[s[i]];
            }
        }

        answer += map[s[s.length() - 1]];

        return answer;
    }
};


//unordered_map 사용 11ms, 7.0MB
/*
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int result = 0;

        for (int i = s.length() - 1; i > 0; i--) {
            if (mp[s[i]] <= mp[s[i - 1]]) {
                result += mp[s[i]];

            }
            else {
                result += mp[s[i]] - mp[s[i - 1]];
                i--;
            }
        }
        if (mp[s[0]] >= mp[s[1]]) {
            result += mp[s[0]];
        }
        return result;
    }
};
*/

//22ms, 8MB
/*
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        vector<int> roman(128);

        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        for (int i = 0; i + 1 < s.length(); ++i)
            if (roman[s[i]] < roman[s[i + 1]])
                ans -= roman[s[i]];
            else
                ans += roman[s[i]];

        return ans + roman[s.back()];
    }
};
*/

int main()
{
    Solution s;
    cout << s.romanToInt("III") << endl;
}