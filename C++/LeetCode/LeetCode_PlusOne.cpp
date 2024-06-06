#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 4ms, 8.8MB로, 속도는 46.19%, 메모리는 13.07% 아래와 같은데 퍼센테이지는 다름.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

//8ms, 8.8MB로, 속도는 9.8%고 메모리는 62.65%. 속도가 너무느림
//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        int r = digits.size() - 1;
//        while (1)
//        {
//            if (digits[r] < 9)
//            {
//                digits[r]++;
//                return digits;
//            }
//            else
//            {
//                digits[r] = 0;
//                if (r == 0)
//                {
//                    digits.insert(digits.begin(), 1);
//                    return digits;
//                }
//                r--;
//            }
//        }
//    }
//};

int main()
{
    Solution s;
}