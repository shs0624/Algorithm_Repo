// 58. Length of Last Word
#include <iostream>
using namespace std;

//수정
//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Length of Last Word.
//Memory Usage : 6.4 MB, less than 88.90 % of C++ online submissions for Length of Last Word.
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (ans != 0 && s[i] == ' ')
            {
                break;
            }
            else if(ans == 0 && s[i] == ' ')
            {
                continue;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};

// 같은 코든데 시간은 더 빠르게 나옴.
//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Length of Last Word.
//Memory Usage : 6.5 MB, less than 52.00 % of C++ online submissions for Length of Last Word.
//다른건 s.length()를 n에 캐싱한것? 그리고 for안에서 return을 하지 않은것
//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        int counter = 0;
//        int n = s.length();
//        for (int i = n - 1; i >= 0; i--) {
//            if (s[i] == ' ' && counter == 0) {
//                continue;
//            }
//            else if (s[i] == ' ' && counter > 0) {
//                break;
//            }
//            else {
//                counter++;
//            }
//        }
//        return counter;
//    }
//};

//내 코드
//Runtime: 5 ms, faster than 26.49 % of C++ online submissions for Length of Last Word.
//Memory Usage : 6.6 MB, less than 52.00 % of C++ online submissions for Length of Last Word.
//class Solution {
//public:
//    int lengthOfLastWord(string s) {
//        int ans = 0;
//        for (int i = s.length() - 1; i >= 0; i--)
//        {
//            if (ans != 0 && s[i] == ' ')
//            {
//                return ans;
//            }
//            else if(ans == 0 && s[i] == ' ')
//            {
//                continue;
//            }
//            else
//            {
//                ans++;
//            }
//        }
//        return ans;
//    }
//};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("luffy is still joyboy") << endl;
}